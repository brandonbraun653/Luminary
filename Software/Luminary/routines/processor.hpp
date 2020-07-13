/********************************************************************************
 *  File Name:
 *    processor.hpp
 *
 *  Description:
 *    Routine processor interface for PWM output animations
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_ROUTINE_PROCESSOR_HPP
#define LUMINARY_ROUTINE_PROCESSOR_HPP

/* STL Includes */
#include <cstdint>

/* Luminary Includes */
#include <Luminary/routines/types.hpp>

namespace Luminary::Routine
{
  void initialize();

  void lock();

  void unlock();

  void startAnimations( const bool reversionary );

  void stepAnimations();

  void stopAnimations();

  void setDefaultAnimation( AnimationCB *animation );

  /**
   *  Sets a new animation to run on the outputs
   *
   *  @param[in]  slot      Which animation sequence to display
   *  @return bool
   */
  void setCurrentAnimation( const Registry slot );

  void registerAnimation( const Registry slot, AnimationSet *animation );

}  // namespace Luminary::Routine

#endif  /* !LUMINARY_ROUTINE_PROCESSOR_HPP */
