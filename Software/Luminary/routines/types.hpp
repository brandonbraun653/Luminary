/********************************************************************************
 *  File Name:
 *    types.hpp
 *
 *  Description:
 *    Light driver output routine types
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_ROUTINE_TYPES_HPP
#define LUMINARY_ROUTINE_TYPES_HPP

/* STL Includes */
#include <array>
#include <cstddef>
#include <cstdint>

/* Luminary Includes */
#include <Luminary/hardware/pwm_output.hpp>

namespace Luminary::Routine
{
  /*-------------------------------------------------------------------------------
  Typedefs
  -------------------------------------------------------------------------------*/
  using PWMPercentOut_t = uint8_t;  /**< PWM output percentage in whole number form */

  /*-------------------------------------------------------------------------------
  Enumerations & Literals
  -------------------------------------------------------------------------------*/
  static constexpr size_t CHANNEL_0 = Hardware::PWM::Channel::PWM_CH_0;
  static constexpr size_t CHANNEL_1 = Hardware::PWM::Channel::PWM_CH_1;
  static constexpr size_t CHANNEL_2 = Hardware::PWM::Channel::PWM_CH_2;

  /*-------------------------------------------------------------------------------
  Structures
  -------------------------------------------------------------------------------*/
  /**
   *  Models the animation control block interface to a single PWM output channel
   */
  struct AnimationCB
  {
    /*-------------------------------------------------
    Properties to be set by animation controller
    -------------------------------------------------*/
    size_t startTime; /**< Time at which the animation began */
    size_t lastTime;  /**< Last time the update procedure was called */

    /*-------------------------------------------------
    Properties to be set by Animator
    -------------------------------------------------*/
    size_t updateDT;  /**< Desired rate at which the update procedure should be called */
    size_t stopTime;  /**< Desired time to stop the animation */
    size_t step;      /**< Current step in the animation sequence */

    /**
     *  Procedure that initializes the animation sequence
     */
    void ( *initialize )(  AnimationCB *cb  );

    /**
     *  Update procedure that retreives the next PWM value in the
     *  animation sequence.
     */
    PWMPercentOut_t ( *update )( AnimationCB *cb );

    /**
     *  Procedure that finishes the animation sequence and cleans up resources
     */
    void ( *destroy )(  AnimationCB *cb  );
  };


  /**
   *  Animation sequence processor data
   */
  struct ProcessorCB
  {
    bool isRunning;     /**< The animation processor is running */
    bool reversionary;  /**< If true, runs the default registered animation */

    AnimationCB *defaultAnimation;
    std::array<AnimationCB*, Hardware::PWM::Channel::NUM_OPTIONS> animations;
  };
}  // namespace Luminary::Routine

#endif  /* !LUMINARY_ROUTINE_TYPES_HPP */
