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
#include <Luminary/routines/animation_flame.hpp>

namespace Luminary::Routine::Flame
{
  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  AnimationCB flameAnimation1;

  /*-------------------------------------------------------------------------------
  Static Data & Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t updateRate = 75*5;

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
    cb->step      = 0;
    cb->updateDT  = updateRate;
  }


  static void destroy( AnimationCB *cb )
  {

  }


  static PWMPercentOut_t update( AnimationCB *cb )
  {
    static PWMPercentOut_t returnVal = 5;

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
    auto random  = rand() % 30 - 15;
    int baseOutput   = 60;
    int actualOutput = baseOutput + random;

    returnVal = static_cast<PWMPercentOut_t>( actualOutput );

    return returnVal;
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct1()
  {
    flameAnimation1.destroy    = destroy;
    flameAnimation1.initialize = initialize;
    flameAnimation1.lastTime   = Chimera::millis();
    flameAnimation1.startTime  = Chimera::millis();
    flameAnimation1.step       = 0;
    flameAnimation1.stopTime   = std::numeric_limits<size_t>::max();
    flameAnimation1.update     = update;
    flameAnimation1.updateDT   = updateRate;
  }


}  // namespace Luminary::Routine::Default
