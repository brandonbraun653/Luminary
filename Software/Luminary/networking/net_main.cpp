/********************************************************************************
 *  File Name:
 *    net_main.cpp
 *
 *  Description:
 *    Networking driver for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>

/* Chimera Includes */
#include <Chimera/common>

/* uLog Includes */
#include <uLog/ulog.hpp>

/* RF24 Includes */
#include <RF24Node/common>
#include <RF24Node/endpoint>

/* Luminary Includes */
#include <Luminary/config/config.hpp>
#include <Luminary/hardware/boot_config.hpp>
#include <Luminary/hardware/power_select.hpp>
#include <Luminary/networking/net_main.hpp>
#include <Luminary/networking/net_connect.hpp>
#include <Luminary/networking/types.hpp>
#include <Luminary/system/sys_event.hpp>

namespace Luminary::Network
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  static constexpr size_t ConnectionRefreshTimeout  = 15 * Chimera::Threading::TIMEOUT_1S;
  static constexpr size_t ConnectionStatusCheckRate = 5000;


  static RF24::Endpoint::SystemInit cfg;
  static RF24::Endpoint::Interface_sPtr radio;
  static std::array<uint8_t, RF24::Network::Frame::PAYLOAD_SIZE> messageBuffer;

  static void bootRadio();


  void initializeModule()
  {
    cfg.clear();
    messageBuffer.fill( 0 );

    /*------------------------------------------------
    Configure the NRF24 radio
    ------------------------------------------------*/
    cfg.physical.dataRate       = RF24::Hardware::DataRate::DR_2MBPS;
    cfg.physical.powerAmplitude = RF24::Hardware::PowerAmplitude::PA_HIGH;
    cfg.physical.rfChannel      = 96;

    /*------------------------------------------------
    GPIO Initialization
    ------------------------------------------------*/
    cfg.physical.spiConfig.validity   = true;
    cfg.physical.spiConfig.externalCS = true;

    cfg.physical.spiConfig.SCKInit.alternate = Chimera::GPIO::Alternate::SPI3_SCK;
    cfg.physical.spiConfig.SCKInit.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    cfg.physical.spiConfig.SCKInit.pin       = 3;
    cfg.physical.spiConfig.SCKInit.port      = Chimera::GPIO::Port::PORTB;
    cfg.physical.spiConfig.SCKInit.pull      = Chimera::GPIO::Pull::NO_PULL;
    cfg.physical.spiConfig.SCKInit.threaded  = true;
    cfg.physical.spiConfig.SCKInit.validity  = true;

    cfg.physical.spiConfig.MISOInit.alternate = Chimera::GPIO::Alternate::SPI3_MISO;
    cfg.physical.spiConfig.MISOInit.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    cfg.physical.spiConfig.MISOInit.pin       = 4;
    cfg.physical.spiConfig.MISOInit.port      = Chimera::GPIO::Port::PORTB;
    cfg.physical.spiConfig.MISOInit.pull      = Chimera::GPIO::Pull::NO_PULL;
    cfg.physical.spiConfig.MISOInit.threaded  = true;
    cfg.physical.spiConfig.MISOInit.validity  = true;

    cfg.physical.spiConfig.MOSIInit.alternate = Chimera::GPIO::Alternate::SPI3_MOSI;
    cfg.physical.spiConfig.MOSIInit.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    cfg.physical.spiConfig.MOSIInit.pin       = 5;
    cfg.physical.spiConfig.MOSIInit.port      = Chimera::GPIO::Port::PORTB;
    cfg.physical.spiConfig.MOSIInit.pull      = Chimera::GPIO::Pull::NO_PULL;
    cfg.physical.spiConfig.MOSIInit.threaded  = true;
    cfg.physical.spiConfig.MOSIInit.validity  = true;

    cfg.physical.spiConfig.CSInit.alternate = Chimera::GPIO::Alternate::NONE;
    cfg.physical.spiConfig.CSInit.drive     = Chimera::GPIO::Drive::OUTPUT_PUSH_PULL;
    cfg.physical.spiConfig.CSInit.pin       = 6;
    cfg.physical.spiConfig.CSInit.port      = Chimera::GPIO::Port::PORTB;
    cfg.physical.spiConfig.CSInit.pull      = Chimera::GPIO::Pull::NO_PULL;
    cfg.physical.spiConfig.CSInit.threaded  = true;
    cfg.physical.spiConfig.CSInit.validity  = true;

    cfg.physical.chipEnableConfig.alternate = Chimera::GPIO::Alternate::NONE;
    cfg.physical.chipEnableConfig.drive     = Chimera::GPIO::Drive::OUTPUT_PUSH_PULL;
    cfg.physical.chipEnableConfig.pin       = 7;
    cfg.physical.chipEnableConfig.port      = Chimera::GPIO::Port::PORTB;
    cfg.physical.chipEnableConfig.pull      = Chimera::GPIO::Pull::NO_PULL;
    cfg.physical.chipEnableConfig.threaded  = true;
    cfg.physical.chipEnableConfig.validity  = true;

    /*------------------------------------------------
    SPI Parameter Initialization
    ------------------------------------------------*/
    cfg.physical.spiConfig.HWInit.validity    = true;
    cfg.physical.spiConfig.HWInit.bitOrder    = Chimera::SPI::BitOrder::MSB_FIRST;
    cfg.physical.spiConfig.HWInit.clockFreq   = 1000000;
    cfg.physical.spiConfig.HWInit.clockMode   = Chimera::SPI::ClockMode::MODE0;
    cfg.physical.spiConfig.HWInit.controlMode = Chimera::SPI::ControlMode::MASTER;
    cfg.physical.spiConfig.HWInit.csMode      = Chimera::SPI::CSMode::MANUAL;
    cfg.physical.spiConfig.HWInit.dataSize    = Chimera::SPI::DataSize::SZ_8BIT;
    cfg.physical.spiConfig.HWInit.hwChannel   = Chimera::SPI::Channel::SPI3;
    cfg.physical.spiConfig.HWInit.txfrMode    = Chimera::SPI::TransferMode::INTERRUPT;
  }


  void MainThread( void *argument )
  {
    Chimera::delayMilliseconds( STARTUP_DELAY_NET_MAIN );

    /*------------------------------------------------
    Radio Initialization
    ------------------------------------------------*/
    bootRadio();

    /*-------------------------------------------------
    Initialize a few variables to help with execution timing
    -------------------------------------------------*/
    size_t reconnectTick = 0;
    bool isRoot          = RF24::isAddressRoot( cfg.network.nodeStaticAddress );

    while ( true )
    {
      /*-------------------------------------------------
      Periodic processing to keep the network alive
      -------------------------------------------------*/
      radio->doAsyncProcessing();

      /*-------------------------------------------------
      Reconnection processing
      -------------------------------------------------*/
      if ( !isRoot && ( ( Chimera::millis() - reconnectTick ) >= ConnectionStatusCheckRate ) )
      {
        reconnectTick = Chimera::millis();
        if ( !radio->isConnected( RF24::Connection::BindSite::PARENT ) )
        {
          doReconnect();
        }
      }

      /*-------------------------------------------------
      Handle any new messages
      -------------------------------------------------*/
      if ( radio->packetAvailable() && ( radio->nextPacketLength() == messageBuffer.size() ) )
      {
        /*-------------------------------------------------
        Read out the message data
        -------------------------------------------------*/
        messageBuffer.fill( 0 );
        radio->read( messageBuffer.data(), messageBuffer.size() );

        /*-------------------------------------------------
        The actual message type is unknown, but the header
        will always be the first few bytes.
        -------------------------------------------------*/
        Msg_Header *header = reinterpret_cast<Msg_Header *>( messageBuffer.data() );
        auto type = header->messageType;

        /*-------------------------------------------------
        Invoke the handler if it exists
        -------------------------------------------------*/
        if( ( type < MessageType::NUM_OPTIONS ) && System::eventCallbacks[ type ] )
        {
          System::eventCallbacks[ type ]( type, messageBuffer.data() );
        }
        else
        {
          uLog::getRootSink()->flog( uLog::Level::LVL_INFO, "%d-APP: Bad handler\n", Chimera::millis());
        }

      }

      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }


  RF24::Endpoint::Interface_sPtr getRadio()
  {
    return radio;
  }


  static void bootRadio()
  {
    using namespace Hardware::Power;
    /*------------------------------------------------
    Initialize local literals
    ------------------------------------------------*/
    static constexpr size_t maxConfigureAttempts = 15;

    /*------------------------------------------------
    Initialize local variables
    ------------------------------------------------*/
    auto logger              = uLog::getRootSink();
    auto configured          = Chimera::CommonStatusCodes::NOT_INITIALIZED;
    size_t configureAttempts = 0;

    /*------------------------------------------------
    Read the GPIO pins to figure out the static network address
    ------------------------------------------------*/
    RF24::LogicalAddress bootAddress   = Hardware::Boot::getNodeAddress();
    RF24::LogicalAddress parentAddress = RF24::getParent( bootAddress );

    /*------------------------------------------------
    Initialize the network parameters
    ------------------------------------------------*/
    cfg.network.mode                = RF24::Network::Mode::NET_MODE_STATIC;
    cfg.network.nodeStaticAddress   = bootAddress;
    cfg.network.parentStaticAddress = parentAddress;
    cfg.network.rxQueueBuffer       = nullptr;
    cfg.network.rxQueueSize         = 5 * RF24::Hardware::PACKET_WIDTH;
    cfg.network.txQueueBuffer       = nullptr;
    cfg.network.txQueueSize         = 5 * RF24::Hardware::PACKET_WIDTH;

    cfg.linkTimeout = ConnectionRefreshTimeout;

    /*------------------------------------------------
    Toggle the radio's power and wait for it to settle
    ------------------------------------------------*/
    setPowerState( RF24_RADIO, RF24_PWR_INACTV_STATE );
    Chimera::delayMilliseconds( RF24_PWR_TURN_ON_DELAY );
    setPowerState( RF24_RADIO, RF24_PWR_ACTIVE_STATE );
    Chimera::delayMilliseconds( RF24_PWR_TURN_OFF_DELAY );

    /*------------------------------------------------
    Create the radio driver and configure to above settings
    ------------------------------------------------*/
    radio = RF24::Endpoint::createShared( cfg );
    radio->attachLogger( uLog::getRootSink() );

    while ( configureAttempts < maxConfigureAttempts )
    {
      /*------------------------------------------------
      Initialize the radio to the desired configuration
      ------------------------------------------------*/
      configured = radio->configure( cfg );
      configureAttempts += 1;

      /*------------------------------------------------
      Toggle the radio's power and wait for it to settle
      ------------------------------------------------*/
      if ( configured == Chimera::CommonStatusCodes::OK )
      {
        break;
      }
      else
      {
        setPowerState( RF24_RADIO, RF24_PWR_INACTV_STATE );
        Chimera::delayMilliseconds( RF24_PWR_TURN_ON_DELAY );
        setPowerState( RF24_RADIO, RF24_PWR_ACTIVE_STATE );
        Chimera::delayMilliseconds( RF24_PWR_TURN_OFF_DELAY );
      }
    }

    /*------------------------------------------------
    Let the user know we couldn't configure the radio
    ------------------------------------------------*/
    if ( configured != Chimera::CommonStatusCodes::OK )
    {
      // TODO: Signal an "uh oh" flash on staus LED
      return;
    }

    /*-------------------------------------------------
    Print debug output to help with testing
    -------------------------------------------------*/
    if ( RF24::isAddressRoot( cfg.network.nodeStaticAddress ) )
    {
      radio->setName( "Master" );
      logger->flog( uLog::Level::LVL_INFO, "%d-APP: Boot as master node\n", Chimera::millis() );
    }
    else
    {
      radio->setName( "Child" );
      logger->flog( uLog::Level::LVL_INFO, "%d-APP: Boot as child node 0%o\n", Chimera::millis(), bootAddress );

      /*-------------------------------------------------
      Connect to the network
      -------------------------------------------------*/
      connect();
    }
  }
}    // namespace Luminary::Network
