/********************************************************************************
 *  File Name:
 *    hwm_main.cpp
 *
 *  Description:
 *    Hardware management implementation file
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/hardware/hwm_main.hpp>
#include <Luminary/hardware/power_select.hpp>
#include <Luminary/hardware/status_led.hpp>

namespace Luminary::Hardware
{
  void initializeModule()
  {
    Luminary::Hardware::StatusLED::initialize();
    Luminary::Hardware::Power::initialize();
  }


  void MainThread( void *argument )
  {
    StatusLED::executeBootFlashSequence();

    while( true )
    {
      // Eventually do other hardware things if needed

      // TODO: Add watchdog kick

      /*-------------------------------------------------
      Blink the status LED if runing a debug build
      -------------------------------------------------*/
      StatusLED::runHeartBeat();

      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }
}