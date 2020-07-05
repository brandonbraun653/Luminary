/********************************************************************************
 *  File Name:
 *    animation_default.cpp
 *
 *  Description:
 *    Default animation definition
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cmath>
#include <cstddef>
#include <limits>

/* Chimera Includes */
#include <Chimera/common>

/* Luminary Includes */
#include <Luminary/routines/animation_sine_wave.hpp>

namespace Luminary::Routine::SineWave
{
  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  AnimationCB sineWaveAnimation;

  /*-------------------------------------------------------------------------------
  Static Data & Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t updateRate = 10;
  static constexpr size_t minStep = 0;
  static constexpr size_t maxStep = 359;

  static constexpr float PI = 3.14159f;

  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void initialize( AnimationCB *cb )
  {
    if( !cb )
    {
      return;
    }

    cb->lastTime  = Chimera::millis();
    cb->startTime = cb->lastTime;
    cb->stopTime  = std::numeric_limits<size_t>::max();
    cb->step      = minStep;
    cb->updateDT  = updateRate;
  }


  static void destroy( AnimationCB *cb )
  {

  }


  static PWMPercentOut_t update( AnimationCB *cb )
  {
    /*-------------------------------------------------
    Input Protection
    -------------------------------------------------*/
    if( !cb )
    {
      return 0;
    }

    /*-------------------------------------------------
    Interpret the "step" value as degrees, convert it
    into radians over a [0.0-1.0] range, then scale to
    the [0-100] range.
    -------------------------------------------------*/
    float idx = static_cast<float>( cb->step );
    float rad = sinf( ( idx * PI ) / 180.0f );
    float shiftedRad = ( rad + 1.0f ) / 2.0f;

    PWMPercentOut_t returnVal = static_cast<PWMPercentOut_t>( shiftedRad * 100.0f );

    /*------------------------------------------------
    Update the step counter
    ------------------------------------------------*/
    cb->step += 5;
    if ( cb->step > maxStep )
    {
      cb->step = minStep;
    }

    return returnVal;
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct()
  {
    sineWaveAnimation.destroy    = destroy;
    sineWaveAnimation.initialize = initialize;
    sineWaveAnimation.lastTime   = Chimera::millis();
    sineWaveAnimation.startTime  = Chimera::millis();
    sineWaveAnimation.step       = 0;
    sineWaveAnimation.stopTime   = std::numeric_limits<size_t>::max();
    sineWaveAnimation.update     = update;
    sineWaveAnimation.updateDT   = updateRate;
  }


}  // namespace Luminary::Routine::Default
