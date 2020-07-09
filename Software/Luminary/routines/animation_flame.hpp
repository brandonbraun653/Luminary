/********************************************************************************
 *  File Name:
 *    animation_flame.hpp
 *
 *  Description:
 *    Declaration of the sine wave animation output for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_ANIMATION_FLAME_HPP
#define LUMINARY_ANIMATION_FLAME_HPP

/* Luminary Includes */
#include <Luminary/routines/types.hpp>

namespace Luminary::Routine::Flame
{
  extern AnimationCB flameAnimation1;
  extern AnimationCB flameAnimation2;
  extern AnimationCB flameAnimation3;

  void construct1();
  void construct2();
  void construct3();

}  // namespace Luminary::Routine::Flame

#endif  /* !LUMINARY_ANIMATION_FLAME_HPP */
