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
#include <cstring>

/* Boost Includes */
#include <boost/circular_buffer.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/serial>
#include <Chimera/thread>
#include <Chimera/watchdog>

/* Luminary Includes */
#include <Luminary/config/config.hpp>
#include <Luminary/rpc/rpc_main.hpp>
#include <Luminary/rpc/rpc_parser.hpp>
#include <Luminary/rpc/types.hpp>
#include <Luminary/hardware/hwm_serial.hpp>

namespace Luminary::RPC
{
  /*-------------------------------------------------------------------------------
  Static Data
  -------------------------------------------------------------------------------*/
  /* Parsing buffer */
  static MessageBuffer sParseBuffer;

  /*-------------------------------------------------------------------------------
  Functions
  -------------------------------------------------------------------------------*/
  void initializeModule()
  {
    /*------------------------------------------------
    Initialize static data
    ------------------------------------------------*/
    sParseBuffer.fill( 0 );

    /*------------------------------------------------
    Additional intialization from other RPC modules
    ------------------------------------------------*/
    initializeParser();
  }


  void MainThread( void *argument )
  {
    Chimera::delayMilliseconds( STARTUP_DELAY_RPC_MAIN );

    /*------------------------------------------------
    Continuously parse the data coming in
    ------------------------------------------------*/
    auto Serial = Chimera::Serial::create_shared_ptr( Hardware::Serial::HWChannel );
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

}    // namespace Luminary::RPC
