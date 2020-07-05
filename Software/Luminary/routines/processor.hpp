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
   *  Sets a new animation to run on the given channel
   *
   *  @param[in]  channel       Which channel to register against
   *  @param[in]  animation     The animation being registered
   *  @return bool
   */
  bool setCurrentAnimation( const Hardware::PWM::Channel channel, AnimationCB *animation );

}  // namespace Luminary::Routine

#endif  /* !LUMINARY_ROUTINE_PROCESSOR_HPP */
