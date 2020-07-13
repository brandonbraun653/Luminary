/********************************************************************************
 *  File Name:
 *    animation_sine_wave.hpp
 *
 *  Description:
 *    Declaration of the sine wave animation output for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_ANIMATION_SINE_WAVE_HPP
#define LUMINARY_ANIMATION_SINE_WAVE_HPP

/* Luminary Includes */
#include <Luminary/routines/types.hpp>

namespace Luminary::Routine::SineWave
{
  extern AnimationSet animations;

  void construct();

}  // namespace Luminary::Routine::SineWave

#endif  /* !LUMINARY_ANIMATION_SINE_WAVE_HPP */
