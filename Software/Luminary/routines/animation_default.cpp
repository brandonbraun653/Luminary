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
#include <Luminary/routines/animation_default.hpp>

namespace Luminary::Routine::Default
{
  /*-------------------------------------------------------------------------------
  Public Data
  -------------------------------------------------------------------------------*/
  AnimationCB defaultAnimation;

  /*-------------------------------------------------------------------------------
  Static Data & Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t updateRate = 50;

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

    return 1;
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct()
  {
    defaultAnimation.destroy    = destroy;
    defaultAnimation.initialize = initialize;
    defaultAnimation.lastTime   = Chimera::millis();
    defaultAnimation.startTime  = Chimera::millis();
    defaultAnimation.stopTime   = std::numeric_limits<size_t>::max();
    defaultAnimation.update     = update;
    defaultAnimation.updateDT   = updateRate;
  }


}  // namespace Luminary::Routine::Default
