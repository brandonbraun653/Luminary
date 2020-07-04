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

/* Luminary Includes */
#include <Luminary/config/config.hpp>
#include <Luminary/system/sys_main.hpp>

namespace Luminary::System
{

  void initializeModule()
  {

  }

  void MainThread( void *argument )
  {
    Chimera::delayMilliseconds( STARTUP_DELAY_SYS_MAIN );

    while( true )
    {

      // Process new commands

      // Process LED outputs

      // Process system debug events



      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }

}  // namespace Luminary::System
