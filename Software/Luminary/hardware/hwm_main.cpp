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
#include <Luminary/hardware/boot_config.hpp>
#include <Luminary/hardware/hwm_main.hpp>
#include <Luminary/hardware/power_select.hpp>
#include <Luminary/hardware/pwm_output.hpp>
#include <Luminary/hardware/status_led.hpp>

namespace Luminary::Hardware
{
  void initializeModule()
  {
    StatusLED::initialize();
    Power::initialize();
  }


  void MainThread( void *argument )
  {
    /*------------------------------------------------
    Immediately read the hardware configuration so other
    resources can consume the GPIO pins used here.
    ------------------------------------------------*/
    Boot::readConfiguration();

    /*------------------------------------------------
    Initialize objects that need the scheduler to be running
    ------------------------------------------------*/
    PWM::initialize();

    PWM::setOutputState( PWM::PWM_CH_0, true );
    PWM::setOutputState( PWM::PWM_CH_1, true );
    PWM::setOutputState( PWM::PWM_CH_2, true );


    StatusLED::executeBootFlashSequence();

    while( true )
    {
      // Eventually do other hardware things if needed

      // TODO: Add watchdog kick

      /*-------------------------------------------------
      Blink the status LED 
      -------------------------------------------------*/
      StatusLED::runHeartBeat();

      Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }
}