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
  extern AnimationCB sineWaveAnimation1;
  extern AnimationCB sineWaveAnimation2;
  extern AnimationCB sineWaveAnimation3;

  void construct1();
  void construct2();
  void construct3();

}  // namespace Luminary::Routine::SineWave

#endif  /* !LUMINARY_ANIMATION_SINE_WAVE_HPP */
