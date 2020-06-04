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
#include <Luminary/system/sys_main.hpp>
#include <Luminary/model/mdl_observables.hpp>

namespace Luminary::System
{

  void initializeModule()
  {

  }

  void MainThread( void *argument )
  {
    

    Model::initializeObservers();

    while( true )
    {
      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }

}  // namespace Luminary::System
