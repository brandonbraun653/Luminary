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
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/config/config.hpp>
#include <Luminary/hardware/boot_config.hpp>
#include <Luminary/routines/animation_default.hpp>
#include <Luminary/routines/animation_flame.hpp>
#include <Luminary/routines/animation_sine_wave.hpp>
#include <Luminary/routines/processor.hpp>
#include <Luminary/system/sys_command.hpp>
#include <Luminary/system/sys_main.hpp>
#include <Luminary/system/sys_event.hpp>

namespace Luminary::System
{
  /*-------------------------------------------------------------------------------
  Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t AnimationChangeTimeout = 10 * Chimera::Threading::TIMEOUT_1S;

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void initializeModule()
  {
    registerEventCallbacks();
  }

  void MainThread( void *argument )
  {
    using namespace Hardware::PWM;

    Chimera::delayMilliseconds( STARTUP_DELAY_SYS_MAIN );

    /*-------------------------------------------------
    Initialize local variables
    -------------------------------------------------*/
    size_t animationSwitchLast = Chimera::millis();

    /*-------------------------------------------------
    Start up the animation sequences
    -------------------------------------------------*/
    Routine::initialize();
    Routine::setDefaultAnimation( &Routine::Default::defaultAnimation );
    Routine::setCurrentAnimation( Routine::Registry::SLOT_1 );
    Routine::startAnimations( false );

    // Just for testing
    Routine::Registry lastAnimation = Luminary::Routine::SLOT_1;

    while ( true )
    {
      /*-------------------------------------------------
      Run the animation sequence processor
      -------------------------------------------------*/
      Routine::stepAnimations();

      /*-------------------------------------------------
      Do some additional work if this node is the master
      -------------------------------------------------*/
      if( Hardware::Boot::getNodeAddress() == MASTER_NODE_ADDR )
      {
        /*-------------------------------------------------
        Is it time for an animation change yet?
        -------------------------------------------------*/
        if( ( Chimera::millis() - animationSwitchLast ) >= AnimationChangeTimeout )
        {
          setGlobalAnimation( lastAnimation );
          animationSwitchLast = Chimera::millis();

          if ( lastAnimation == Routine::Registry::SLOT_0 )
          {
            lastAnimation = Luminary::Routine::SLOT_1;
          }
          else
          {
            lastAnimation = Luminary::Routine::SLOT_0;
          }
        }
      }

      // Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }

}    // namespace Luminary::System
