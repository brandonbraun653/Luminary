/********************************************************************************
 *  File Name:
 *    animation_default.hpp
 *
 *  Description:
 *    Declaration of the default animation output for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_ANIMATION_DEFAULT_HPP
#define LUMINARY_ANIMATION_DEFAULT_HPP

/* Luminary Includes */
#include <Luminary/routines/types.hpp>

namespace Luminary::Routine::Default
{
  extern AnimationCB defaultAnimation;

  void construct();

}  // namespace Luminary::Routine::Default

#endif  /* !LUMINARY_ANIMATION_DEFAULT_HPP */
