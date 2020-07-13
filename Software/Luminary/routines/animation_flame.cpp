/********************************************************************************
 *  File Name:
 *    animation_flame.cpp
 *
 *  Description:
 *    Flame animation definition
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* STL Includes */
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <limits>

/* Chimera Includes */
#include <Chimera/common>

/* Luminary Includes */
#include <Luminary/routines/types.hpp>
#include <Luminary/routines/animation_flame.hpp>

namespace Luminary::Routine::Flame
{
  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  AnimationSet animations;

  /*-------------------------------------------------------------------------------
  Static Functions
  -------------------------------------------------------------------------------*/
  static void initialize( AnimationCB *cb )
  {
    if ( !cb || ( cb->type != AnimationType::FLAME ) )
    {
      return;
    }

    cb->lastTime  = Chimera::millis();
    cb->startTime = cb->lastTime;
    cb->stopTime  = std::numeric_limits<size_t>::max();
    cb->updateDT  = cb->data.flame.updateRate;
  }


  static void destroy( AnimationCB *cb )
  {
  }


  static PWMPercentOut_t update( AnimationCB *cb )
  {
    /*-------------------------------------------------
    Input Protection
    -------------------------------------------------*/
    if ( !cb || ( cb->type != AnimationType::FLAME ) )
    {
      return 0;
    }

    /*-------------------------------------------------
    Generate some random data to display
    -------------------------------------------------*/
    auto random    = ( rand() % cb->data.flame.modulus ) - ( cb->data.flame.modulus / 2 );
    int baseOutput = static_cast<int>( cb->data.flame.baseOutput );

    return static_cast<PWMPercentOut_t>( baseOutput + random );
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct()
  {
    /*-------------------------------------------------
    Channel 0 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.flame.baseOutput = 60;
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.flame.modulus    = 30;
    animations[ Hardware::PWM::Channel::PWM_CH_0 ].data.flame.updateRate = 75 * 5;

    /*-------------------------------------------------
    Channel 1 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.flame.baseOutput = 40;
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.flame.modulus    = 20;
    animations[ Hardware::PWM::Channel::PWM_CH_1 ].data.flame.updateRate = 150 * 5;

    /*-------------------------------------------------
    Channel 2 Data
    -------------------------------------------------*/
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.flame.baseOutput = 80;
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.flame.modulus    = 40;
    animations[ Hardware::PWM::Channel::PWM_CH_2 ].data.flame.updateRate = 25 * 5;

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
      tmp.type       = AnimationType::FLAME;
      tmp.updateDT   = tmp.data.flame.updateRate;
    }
  }


}    // namespace Luminary::Routine::Flame
