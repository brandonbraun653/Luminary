/********************************************************************************
 *  File Name:
 *    rpc_main.cpp
 *
 *  Description:
 *    Simplified RPC handling for invoking functions based on serial commands
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>

/* Boost Includes */
#include <boost/circular_buffer.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/serial>
#include <Chimera/thread>
#include <Chimera/watchdog>

/* Luminary Includes */
#include <Luminary/rpc/rpc_main.hpp>
#include <Luminary/rpc/rpc_parser.hpp>
#include <Luminary/rpc/types.hpp>

namespace Luminary::RPC
{
  /*-------------------------------------------------
  Module Data
  -------------------------------------------------*/
  /* Serial Object */
  static Chimera::Serial::Serial_sPtr Serial;

  /* Serial Transmit Buffers */
  static MessageBuffer sTXHWBuffer;
  static CircularBuffer sTXCircularBuffer( CircularBufferSize );

  /* Serial Recieve Buffers */
  static MessageBuffer sRXHWBuffer;
  static CircularBuffer sRXCircularBuffer( CircularBufferSize );

  /* Parsing buffer */
  static MessageBuffer sParseBuffer;

  /*-------------------------------------------------
  Module Functions
  -------------------------------------------------*/
  static Chimera::Status_t initializeSerial();


  void initializeModule()
  {
    /*------------------------------------------------
    Initialize static data
    ------------------------------------------------*/
    Serial = nullptr;
    sRXHWBuffer.fill( 0 );
    sTXHWBuffer.fill( 0 );
    sParseBuffer.fill( 0 );
    sRXCircularBuffer.clear();
    sTXCircularBuffer.clear();

    /*------------------------------------------------
    Additional intialization from other RPC modules
    ------------------------------------------------*/
    initializeParser();
  }


  void MainThread( void *argument )
  {
    /*-------------------------------------------------
    Initialize the serial object used to send/receive commands
    -------------------------------------------------*/
    if ( initializeSerial() != Chimera::CommonStatusCodes::OK )
    {
      Chimera::insert_debug_breakpoint();
      Chimera::Watchdog::invokeTimeout();
    }

    /*------------------------------------------------
    Continuously parse the data coming in
    ------------------------------------------------*/
    size_t bytesToRead  = 0;
    size_t responseSize = 0;
    Serial->toggleAsyncListening( true );

    while ( true )
    {
      /*-------------------------------------------------
      Any data arrived? If so, parse it.
      -------------------------------------------------*/
      if ( Serial->available( &bytesToRead ) )
      {
        sParseBuffer.fill( 0 );
        Serial->readAsync( sParseBuffer.data(), bytesToRead );

        /*-------------------------------------------------
        Assuming the parsing produced a return message, send it off
        -------------------------------------------------*/
        if ( auto responseSize = parseCommand( sParseBuffer ) )
        {
          Serial->write( sParseBuffer.data(), responseSize, Chimera::Threading::TIMEOUT_25MS );
          Serial->await( Chimera::Event::TRIGGER_WRITE_COMPLETE, Chimera::Threading::TIMEOUT_25MS );
        }

        /*------------------------------------------------
        Turn on listening again so we can receive more messages
        ------------------------------------------------*/
        Serial->toggleAsyncListening( true );
      }

      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }


  static Chimera::Status_t initializeSerial()
  {
    using namespace Chimera::Serial;
    using namespace Chimera::Hardware;

    /*------------------------------------------------
    Configuration info for the serial object
    ------------------------------------------------*/
    IOPins pins;
    pins.tx.alternate = Chimera::GPIO::Alternate::USART1_TX;
    pins.tx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    pins.tx.pin       = 9;
    pins.tx.port      = Chimera::GPIO::Port::PORTA;
    pins.tx.pull      = Chimera::GPIO::Pull::NO_PULL;
    pins.tx.threaded  = true;
    pins.tx.validity  = true;

    pins.rx.alternate = Chimera::GPIO::Alternate::USART1_RX;
    pins.rx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    pins.rx.pin       = 10;
    pins.rx.port      = Chimera::GPIO::Port::PORTA;
    pins.rx.pull      = Chimera::GPIO::Pull::NO_PULL;
    pins.rx.threaded  = true;
    pins.rx.validity  = true;


    Config cfg;
    cfg.baud     = 115200;
    cfg.flow     = FlowControl::FCTRL_NONE;
    cfg.parity   = Parity::PAR_NONE;
    cfg.stopBits = StopBits::SBITS_ONE;
    cfg.width    = CharWid::CW_8BIT;

    /*------------------------------------------------
    Create the serial object and initialize it
    ------------------------------------------------*/
    auto result = Chimera::CommonStatusCodes::OK;
    Serial    = create_shared_ptr( Channel::SERIAL1 );

    result |= Serial->assignHW( Channel::SERIAL1, pins );
    result |= Serial->configure( cfg );
    result |= Serial->enableBuffering( SubPeripheral::TX, &sTXCircularBuffer, sTXHWBuffer.data(),
                                         sTXHWBuffer.size() );
    result |= Serial->enableBuffering( SubPeripheral::RX, &sRXCircularBuffer, sRXHWBuffer.data(),
                                         sRXHWBuffer.size() );
    result |= Serial->begin( PeripheralMode::INTERRUPT, PeripheralMode::INTERRUPT );

    return result;
  }

}    // namespace Luminary::RPC
