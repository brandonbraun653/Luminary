/********************************************************************************
 *  File Name:
 *    log_main.cpp
 *
 *  Description:
 *    Logging implementation for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Aurora Includes */
#include <Aurora/logging/serial_sink.hpp>
#include <Aurora/logging/serial_sink_config.hpp>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/event>
#include <Chimera/system>

/* uLog Includes */
#include <uLog/ulog.hpp>
#include <uLog/sinks/sink_vgdb_semihosting.hpp>

/* Luminary Includes */
#include <Luminary/logging/log_main.hpp>
#include <Luminary/version.hpp>


namespace Chimera::Modules::uLog
{
 Chimera::Serial::IOPins SerialPins;
}


namespace Luminary::Logging
{
  uLog::SinkHandle rootSink;

  static void printBootMessage();

  void initializeModule()
  {
    /*------------------------------------------------
    Initialize the logger system
    ------------------------------------------------*/
    uLog::initialize();

#undef USING_VISUAL_GDB
#if defined( USING_VISUAL_GDB )
    rootSink = std::make_shared<uLog::VGDBSemihostingSink>();
    rootSink->setLogLevel( uLog::Level::LVL_DEBUG );
    rootSink->setName( "Root" );
    rootSink->enable();

    uLog::registerSink( rootSink );
    uLog::setGlobalLogLevel( uLog::Level::LVL_DEBUG );
    uLog::setRootSink( rootSink );
#else
    using namespace Chimera::Modules::uLog;
    rootSink = std::make_shared<SerialSink>();

    SerialPins.tx.alternate = Chimera::GPIO::Alternate::USART1_TX;
    SerialPins.tx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    SerialPins.tx.pin       = 9;
    SerialPins.tx.port      = Chimera::GPIO::Port::PORTA;
    SerialPins.tx.pull      = Chimera::GPIO::Pull::NO_PULL;
    SerialPins.tx.threaded  = true;
    SerialPins.tx.validity  = true;

    SerialPins.rx.alternate = Chimera::GPIO::Alternate::USART1_RX;
    SerialPins.rx.drive     = Chimera::GPIO::Drive::ALTERNATE_PUSH_PULL;
    SerialPins.rx.pin       = 10;
    SerialPins.rx.port      = Chimera::GPIO::Port::PORTA;
    SerialPins.rx.pull      = Chimera::GPIO::Pull::NO_PULL;
    SerialPins.rx.threaded  = true;
    SerialPins.rx.validity  = true;

    rootSink->setLogLevel( uLog::Level::LVL_DEBUG );
    rootSink->setName( "Root" );
    rootSink->enable();
    rootSink->open();

    uLog::registerSink( rootSink );
    uLog::setGlobalLogLevel( uLog::Level::LVL_DEBUG );
    uLog::setRootSink( rootSink );
#endif
  }

  void MainThread( void *argument )
  {
    initializeModule();
    printBootMessage();

    while( true )
    {
      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }


  static void printBootMessage()
  {
    /*------------------------------------------------
    Initialize the buffer
    ------------------------------------------------*/
    size_t offset = 0;
    std::array<char, 100> bootMsg;
    bootMsg.fill( 0 );

    /*------------------------------------------------
    Format the boot string
    ------------------------------------------------*/
    offset += snprintf( bootMsg.data() + offset, bootMsg.size() - offset, "Booting up Luminary\r\n");
    offset += snprintf( bootMsg.data() + offset, bootMsg.size() - offset, "Luminary Version: %s\r\n", Luminary::Version.data() );
    offset += snprintf( bootMsg.data() + offset, bootMsg.size() - offset, "%s Version: %s\r\n",
                        Chimera::System::Description::backendDriverName().data(), Chimera::System::Version::asString().data() );

    /*------------------------------------------------
    Print out the boot message to the console
    ------------------------------------------------*/
    auto logger = uLog::getRootSink();
    if ( logger->try_lock_for( 100 ) )
    {
      logger->log( uLog::Level::LVL_DEBUG, bootMsg.data(), strlen( bootMsg.data() ) );
      Chimera::delayMilliseconds( 50 );
      logger->unlock();
    }
  }
}  // namespace Luminary::Loggin
