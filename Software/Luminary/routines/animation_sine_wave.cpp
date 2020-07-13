/********************************************************************************
 *  File Name:
 *    animation_sine_wave.cpp
 *
 *  Description:
 *    Sine wave animation definition
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
  AnimationSet animations;

  /*-------------------------------------------------------------------------------
  Static Data & Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t minStep = 0;
  static constexpr size_t maxStep = 359;

  static constexpr float PI = 3.14159f;

  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void initialize( AnimationCB *cb )
  {
    if( !cb || ( cb->type != AnimationType::SINEWAVE ) )
    {
      return;
    }

    cb->lastTime  = Chimera::millis();
    cb->startTime = cb->lastTime;
    cb->stopTime  = std::numeric_limits<size_t>::max();
    cb->updateDT  = cb->data.sinewave.updateRate;
  }


  static void destroy( AnimationCB *cb )
  {

  }


  static PWMPercentOut_t update( AnimationCB *cb )
  {
    /*-------------------------------------------------
    Input Protection
    -------------------------------------------------*/
    if( !cb || ( cb->type != AnimationType::SINEWAVE ) )
    {
      return 0;
    }

    /*-------------------------------------------------
    Interpret the "step" value as degrees, convert it
    into radians over a [0.0-1.0] range, then scale to
    the [0-100] range.
    -------------------------------------------------*/
    float idx = static_cast<float>( cb->data.sinewave.step );
    float rad = sinf( ( idx * PI ) / 180.0f );
    float shiftedRad = ( rad + 1.0f ) / 2.0f;

    PWMPercentOut_t returnVal = static_cast<PWMPercentOut_t>( shiftedRad * 100.0f );

    /*------------------------------------------------
    Update the step counter
    ------------------------------------------------*/
    cb->data.sinewave.step += 5;
    if ( cb->data.sinewave.step > maxStep )
    {
      cb->data.sinewave.step = minStep;
    }

    return returnVal;
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct()
  {
    /*-------------------------------------------------
    Channel 0 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.sinewave.updateRate = 43;
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.sinewave.step       = 15;

    /*-------------------------------------------------
    Channel 1 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.sinewave.updateRate = 83;
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.sinewave.step       = 45;

    /*-------------------------------------------------
    Channel 2 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.sinewave.updateRate = 133;
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.sinewave.step       = 90;

    /*-------------------------------------------------
    Common data for all animation types
    -------------------------------------------------*/
    for ( auto &tmp : animations )
    {
      tmp.destroy    = destroy;
      tmp.initialize = initialize;
      tmp.lastTime   = Chimera::millis();
      tmp.startTime  = Chimera::millis();
      tmp.stopTime   = std::numeric_limits<size_t>::max();
      tmp.update     = update;
      tmp.type       = AnimationType::SINEWAVE;
      tmp.updateDT   = tmp.data.sinewave.updateRate;
    }
  }


}  // namespace Luminary::Routine::Default
