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
#include <Luminary/routines/animation_flame.hpp>

namespace Luminary::System
{

  void initializeModule()
  {

  }

  void MainThread( void *argument )
  {
    using namespace Hardware::PWM;
    
    Chimera::delayMilliseconds( STARTUP_DELAY_SYS_MAIN );

    /*-------------------------------------------------
    Start up the animation sequences
    -------------------------------------------------*/
    Routine::initialize();
    Routine::setDefaultAnimation( &Routine::Default::defaultAnimation );
//    Routine::setCurrentAnimation( Channel::PWM_CH_0, &Routine::Flame::flameAnimation1 );
//    Routine::setCurrentAnimation( Channel::PWM_CH_1, &Routine::Flame::flameAnimation2 );
//    Routine::setCurrentAnimation( Channel::PWM_CH_2, &Routine::Flame::flameAnimation3 );

    Routine::setCurrentAnimation( Channel::PWM_CH_0, &Routine::SineWave::sineWaveAnimation1 );
    Routine::setCurrentAnimation( Channel::PWM_CH_1, &Routine::SineWave::sineWaveAnimation2 );
    Routine::setCurrentAnimation( Channel::PWM_CH_2, &Routine::SineWave::sineWaveAnimation3 );

    Routine::startAnimations( false );

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
