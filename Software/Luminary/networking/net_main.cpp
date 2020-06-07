/********************************************************************************
 *  File Name:
 *    net_main.cpp
 *
 *  Description:
 *    Networking driver for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>

/* uLog Includes */
#include <uLog/ulog.hpp>
#include <uLog/sinks/sink_intf.hpp>

/* RF24 Includes */
#include <RF24Node/common>
#include <RF24Node/endpoint>

/* Luminary Includes */
#include <Luminary/config/config.hpp>
#include <Luminary/hardware/boot_config.hpp>
#include <Luminary/networking/net_main.hpp>
#include <Luminary/networking/net_connect.hpp>

namespace Luminary::Network
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  static constexpr size_t ConnectionRefreshTimeout = 15 * Chimera::Threading::TIMEOUT_1S;
  static constexpr size_t ConnectionStatusCheckRate = 5000;


  static RF24::Endpoint::SystemInit cfg;
  static RF24::Endpoint::Interface_sPtr radio;


  void initializeModule()
  {
    cfg.clear();

    /*------------------------------------------------
    Configure the NRF24 radio
    ------------------------------------------------*/
    cfg.physical.dataRate       = RF24::Hardware::DataRate::DR_1MBPS;
    cfg.physical.powerAmplitude = RF24::Hardware::PowerAmplitude::PA_LOW;
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
    // Delay a bit to allow other systems to set up
    Chimera::delayMilliseconds( 500 );

    /*------------------------------------------------
    Radio Initialization
    ------------------------------------------------*/
    RF24::LogicalAddress bootAddress   = Hardware::Boot::getNodeAddress();
    RF24::LogicalAddress parentAddress = RF24::getParent( bootAddress );

#if defined( LUMINARY_MASTER )
    bootAddress = 00001;
    parentAddress = RF24::getParent( bootAddress );
#endif

    cfg.network.mode                = RF24::Network::Mode::NET_MODE_STATIC;
    cfg.network.nodeStaticAddress   = bootAddress;
    cfg.network.parentStaticAddress = parentAddress;
    cfg.network.rxQueueBuffer       = nullptr;
    cfg.network.rxQueueSize         = 5 * RF24::Hardware::PACKET_WIDTH;
    cfg.network.txQueueBuffer       = nullptr;
    cfg.network.txQueueSize         = 5 * RF24::Hardware::PACKET_WIDTH;

    cfg.linkTimeout = ConnectionRefreshTimeout;

    /*------------------------------------------------
    Create the radio driver and reset to above settings
    ------------------------------------------------*/
    auto logger = uLog::getRootSink();

    radio = RF24::Endpoint::createShared( cfg );
    radio->attachLogger( uLog::getRootSink() );
    radio->configure( cfg );

    /*-------------------------------------------------
    Print debug output to help with testing
    -------------------------------------------------*/
    bool isChild = false;
    if( RF24::isAddressRoot( cfg.network.nodeStaticAddress ) )
    {
      radio->setName( "Master" );
      logger->flog( uLog::Level::LVL_INFO, "%d-APP: Boot as master node\n", Chimera::millis() );
    }
    else
    {
      isChild = true;
      radio->setName( "Child" );
      logger->flog( uLog::Level::LVL_INFO, "%d-APP: Boot as child node 0%o\n", Chimera::millis(), bootAddress );

      /*-------------------------------------------------
      Connect to the network
      -------------------------------------------------*/
      connect();
    }

    /*-------------------------------------------------
    Initialize a few variables to help with execution timing
    -------------------------------------------------*/
    size_t reconnectTick = 0;

    while ( true )
    {
      /*-------------------------------------------------
      Periodic processing to keep the network alive
      -------------------------------------------------*/
      radio->doAsyncProcessing();

      /*-------------------------------------------------
      Reconnection processing
      -------------------------------------------------*/
      if( isChild && ( ( Chimera::millis() - reconnectTick ) >= ConnectionStatusCheckRate ) )
      {
        reconnectTick = Chimera::millis();
        if( !radio->isConnected() )
        {
          doReconnect();
        }
      }

      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }


  RF24::Endpoint::Interface_sPtr getRadio()
  {
    return radio;
  }

}    // namespace Luminary::Network
