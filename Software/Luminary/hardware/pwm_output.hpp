/********************************************************************************
 *  File Name:
 *    pwm_output.hpp
 *
 *  Description:
 *    PWM interface for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_PWM_DRIVER_HPP
#define LUMINARY_PWM_DRIVER_HPP

/* STL Includes */
#include <cstdint>

namespace Luminary::Hardware::PWM
{
  /*-------------------------------------------------------------------------------
  Literals
  -------------------------------------------------------------------------------*/
  #pragma message("Invert these values when new hardware comes in!")
  static constexpr size_t PWM_MIN_DUTY_CYCLE = 99;
  static constexpr size_t PWM_MAX_DUTY_CYCLE = 1;

  /*-------------------------------------------------------------------------------
  Types & Enumerations
  -------------------------------------------------------------------------------*/
  using DutyCycle_t = uint8_t;

  /**
   *  Controllable output PWM channels on the Luminary board
   */
  enum Channel : uint8_t
  {
    PWM_CH_0,
    PWM_CH_1,
    PWM_CH_2,

    NUM_OPTIONS,
    INVALID
  };

  /*-------------------------------------------------------------------------------
  Functions
  -------------------------------------------------------------------------------*/
  /**
   *  Initializes the memory associated with this module
   *  @return void
   */
  void initialize();


  void setOutputState( const Channel channel, const bool state );


  void updateDutyCycle( const Channel channel, const DutyCycle_t dc );


  void setScale( const Channel channel, const float scale );

}  // namespace Luminary::Hardware::PWM

#endif  /* !LUMINARY_PWM_DRIVER_HPP */
