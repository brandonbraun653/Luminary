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
  AnimationSet animations;

  /*-------------------------------------------------------------------------------
  Static Data & Literals
  -------------------------------------------------------------------------------*/
  static constexpr AnimationType expectedType = AnimationType::DEFAULT;

  /*-------------------------------------------------------------------------------
  Static Data & Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t updateRate = 50;

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
    if( !cb || ( cb->type != expectedType ) )
    {
      return 0;
    }

    return 25;
  }


  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  void construct()
  {
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
      tmp.updateDT   = tmp.data.dflt.updateRate;
    }
  }


}  // namespace Luminary::Routine::Default
