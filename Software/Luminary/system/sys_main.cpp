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
#include <Luminary/routines/processor.hpp>
#include <Luminary/routines/animation_default.hpp>
#include <Luminary/routines/animation_sine_wave.hpp>

namespace Luminary::System
{

  void initializeModule()
  {

  }

  void MainThread( void *argument )
  {
    Chimera::delayMilliseconds( STARTUP_DELAY_SYS_MAIN );

    /*-------------------------------------------------
    Start up the animation sequences
    -------------------------------------------------*/
    Routine::initialize();
    Routine::setDefaultAnimation( &Routine::SineWave::sineWaveAnimation );
    Routine::startAnimations( true );

    while( true )
    {
      /*-------------------------------------------------
      Run the animation sequence processor
      -------------------------------------------------*/
      Routine::stepAnimations();


      //Chimera::delayMilliseconds( MainThreadUpdateRate );
    }
  }

}  // namespace Luminary::System
