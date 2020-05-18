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
#include <Luminary/hardware/status_led.hpp>

namespace Luminary::Hardware
{

  void MainThread( void *argument )
  {
    size_t currentTick = Chimera::millis();

#if defined( DEBUG )
    StatusLED::initialize();
    StatusLED::executeBootFlashSequence();
#endif

    while( true )
    {
      currentTick = Chimera::millis();

#if defined( DEBUG )
      /*-------------------------------------------------
      Blink the status LED if runing a debug build
      -------------------------------------------------*/
      StatusLED::runHeartBeat();
#endif


      Chimera::delayMilliseconds( MainThreadUpdateRate );

    }
  }
}