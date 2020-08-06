/********************************************************************************
 *  File Name:
 *    sys_main.cpp
 *
 *  Description:
 *    System level functionality for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <array>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

/* uLog Includes */
#include <uLog/ulog.hpp>

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
  Static Data and Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t AnimationChangeTimeout = 5 * Chimera::Threading::TIMEOUT_1MIN;

  static std::array<Routine::Registry, 5> animationSequence;
  static size_t animationIndex = 0;

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
    Routine::setCurrentAnimation( Routine::Registry::SLOT_DEFAULT );
    Routine::startAnimations();

    animationIndex         = 0;
    animationSequence[ 0 ] = Luminary::Routine::SLOT_0;
    animationSequence[ 1 ] = Luminary::Routine::SLOT_1;
    animationSequence[ 2 ] = Luminary::Routine::SLOT_2;
    animationSequence[ 3 ] = Luminary::Routine::SLOT_3;
    animationSequence[ 4 ] = Luminary::Routine::SLOT_4;

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
          setGlobalAnimation( animationSequence[ animationIndex ] );
          animationSwitchLast = Chimera::millis();
          animationIndex++;

          if ( animationIndex >= animationSequence.size() ) 
          {
            animationIndex = 0;
          }
        }
      }
    }
  }

}    // namespace Luminary::System
