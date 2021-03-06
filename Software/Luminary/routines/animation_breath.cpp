/********************************************************************************
 *  File Name:
 *    animation_breath.cpp
 *
 *  Description:
 *    Breath animation definition
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
#include <Luminary/routines/types.hpp>
#include <Luminary/routines/animation_breath.hpp>

namespace Luminary::Routine::Breath
{
  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  AnimationSet animations;

  /*-------------------------------------------------------------------------------
  Static Data & Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t minStep = 75;
  static constexpr size_t maxStep = 250;
  static constexpr AnimationType expectedType = AnimationType::BREATH;

  static constexpr float PI = 3.14159f;
  static bool count_up = false;

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
    cb->updateDT  = cb->data.breath.updateRate;
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
    float idx = static_cast<float>( cb->data.breath.step );
    float rad = sinf( ( idx * PI ) / 180.0f );
    float shiftedRad = ( rad + 1.0f ) / 2.0f;

    PWMPercentOut_t returnVal = static_cast<PWMPercentOut_t>( shiftedRad * 100.0f );

    /*------------------------------------------------
    Update the step counter
    ------------------------------------------------*/
    if ( cb->data.breath.count_up )
    {
      cb->data.breath.step += 5;
    }
    else
    {
      cb->data.breath.step -= 5;
    }


    if ( cb->data.breath.step >= maxStep )
    {
      cb->data.breath.count_up = false;
      cb->data.breath.step = maxStep;
    }
    else if( cb->data.breath.step <= minStep )
    {
      cb->data.breath.count_up = true;
      cb->data.breath.step = minStep;
    }

    return returnVal;
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct()
  {
    static constexpr size_t updateRate = 85;
    static constexpr size_t phaseCh0 = minStep;
    static constexpr size_t phaseCh1 = minStep;
    static constexpr size_t phaseCh2 = minStep;

    /*-------------------------------------------------
    Channel 0 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.breath.updateRate = updateRate;
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.breath.step       = phaseCh0;
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.breath.lastTime   = Chimera::millis();

    /*-------------------------------------------------
    Channel 1 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.breath.updateRate = updateRate;
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.breath.step       = phaseCh1;
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.breath.lastTime   = Chimera::millis();

    /*-------------------------------------------------
    Channel 2 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.breath.updateRate = updateRate;
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.breath.step       = phaseCh2;
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.breath.lastTime   = Chimera::millis();

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
      tmp.updateDT   = tmp.data.breath.updateRate;
      tmp.data.breath.count_up = true;
    }
  }
}    // namespace Luminary::Routine::Breath
