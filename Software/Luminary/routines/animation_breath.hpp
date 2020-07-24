/********************************************************************************
 *  File Name:
 *    animation_breath.hpp
 *
 *  Description:
 *    Declaration of the breath animation output for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_ANIMATION_BREATH_HPP
#define LUMINARY_ANIMATION_BREATH_HPP

/* Luminary Includes */
#include <Luminary/routines/types.hpp>

namespace Luminary::Routine::Breath
{
  extern AnimationSet animations;

  void construct();

}  // namespace Luminary::Routine::Breath

#endif  /* !LUMINARY_ANIMATION_BREATH_HPP */
