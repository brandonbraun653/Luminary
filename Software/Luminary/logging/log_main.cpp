/********************************************************************************
 *  File Name:
 *    log_main.cpp
 *
 *  Description:
 *    Logging implementation for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>

/* uLog Includes */
#include <uLog/ulog.hpp>
#include <uLog/sinks/sink_vgdb_semihosting.hpp>

/* Luminary Includes */
#include <Luminary/logging/log_main.hpp>

namespace Luminary::Logging
{
  uLog::SinkHandle rootSink;

  void initializeModule()
  {
    /*------------------------------------------------
    Initialize the logger system
    ------------------------------------------------*/
    uLog::initialize();

#if defined( USING_VISUAL_GDB )
    rootSink = std::make_shared<uLog::VGDBSemihostingSink>();
    rootSink->setLogLevel( uLog::Level::LVL_DEBUG );
    rootSink->setName( "Root" );
    rootSink->enable();

    uLog::registerSink( rootSink );
    uLog::setGlobalLogLevel( uLog::Level::LVL_DEBUG );
    uLog::setRootSink( rootSink );

    rootSink->flog( uLog::Level::LVL_INFO, "Boot up the world!\n" );
#endif
  }

  void MainThread( void *argument )
  {

    while( true )
    {
      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }
}  // namespace Luminary::Loggin
