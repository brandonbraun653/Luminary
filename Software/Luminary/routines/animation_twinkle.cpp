/********************************************************************************
 *  File Name:
 *    animation_twinkle.cpp
 *
 *  Description:
 *    Twinkle animation definition
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
#include <Luminary/routines/animation_twinkle.hpp>

namespace Luminary::Routine::Twinkle
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
  static constexpr AnimationType expectedType = AnimationType::TWINKLE;

  static constexpr float PI = 3.14159f;

  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void initialize( AnimationCB *cb )
  {
    if( !cb || ( cb->type != expectedType ) )
    {
      return;
    }

    cb->lastTime  = Chimera::millis();
    cb->startTime = cb->lastTime;
    cb->stopTime  = std::numeric_limits<size_t>::max();
    cb->updateDT  = cb->data.twinkle.updateRate;
  }


  static void destroy( AnimationCB *cb )
  {

  }


  static PWMPercentOut_t update( AnimationCB *cb )
  {
    /*-------------------------------------------------
    Input Protection
    -------------------------------------------------*/
    if( !cb || ( cb->type != expectedType ) )
    {
      return 0;
    }

    /*-------------------------------------------------
    Interpret the "step" value as degrees, convert it
    into radians over a [0.0-1.0] range, then scale to
    the [0-100] range.
    -------------------------------------------------*/
    float idx = static_cast<float>( cb->data.twinkle.step );
    float rad = sinf( ( idx * PI ) / 180.0f );
    float shiftedRad = ( rad + 1.0f ) / 2.0f;

    PWMPercentOut_t returnVal = static_cast<PWMPercentOut_t>( shiftedRad * 100.0f );

    /*------------------------------------------------
    Update the step counter
    ------------------------------------------------*/
    // Accelerate through the high/low points

    if ( ( cb->data.twinkle.step > 320 ) || ( cb->data.twinkle.step < 40 ) ) 
    {
      cb->data.twinkle.step += 15;
    }
    else
    {
      cb->data.twinkle.step += 2;
    }

    if ( cb->data.twinkle.step > maxStep )
    {
      cb->data.twinkle.step = minStep;
    }

    return returnVal;
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct()
  {
    static constexpr size_t updateRate = 25;
    static constexpr size_t phaseCh0 = 0;
    static constexpr size_t phaseCh1 = 120;
    static constexpr size_t phaseCh2 = 240;

    /*-------------------------------------------------
    Channel 0 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.twinkle.updateRate = updateRate;
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.twinkle.step       = phaseCh0;

    /*-------------------------------------------------
    Channel 1 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.twinkle.updateRate = updateRate;
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.twinkle.step       = phaseCh1;

    /*-------------------------------------------------
    Channel 2 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.twinkle.updateRate = updateRate;
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.twinkle.step       = phaseCh2;

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
      tmp.type       = expectedType;
      tmp.updateDT   = tmp.data.twinkle.updateRate;
    }
  }


}  // namespace Luminary::Routine::Default
