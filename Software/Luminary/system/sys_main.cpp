/********************************************************************************
 *  File Name:
 *    sys_main.cpp
 *
 *  Description:
 *    System level functionality for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>

/* Logger Includes */
#include <uLog/ulog.hpp>
#include <uLog/sinks/sink_vgdb_semihosting.hpp>

/* Luminary Includes */
#include <Luminary/system/sys_main.hpp>

namespace Luminary::System
{

  void initializeModule()
  {
    /*-------------------------------------------------
    Initialize the system logger instances
    -------------------------------------------------*/
    uLog::initialize();

    // uLog::SinkHandle rootSink = std::make_shared<uLog::VGDBSemihostingSink>();
    // rootSink->setLogLevel( uLog::Level::LVL_DEBUG );
    // rootSink->setName( "Root" );
    // rootSink->enable();

    // uLog::registerSink( rootSink );
    // uLog::setGlobalLogLevel( uLog::Level::LVL_DEBUG );
    // uLog::setRootSink( rootSink );


  }

  void MainThread( void *argument )
  {

    while( true )
    {
      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }

}  // namespace Luminary::System
