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
  Forward Declarations
  -------------------------------------------------------------------------------*/
  struct AnimationCB;

  /*-------------------------------------------------------------------------------
  Typedefs
  -------------------------------------------------------------------------------*/
  using PWMPercentOut_t = uint8_t;  /**< PWM output percentage in whole number form */
  using AnimationSet = std::array<AnimationCB, Hardware::PWM::Channel::NUM_OPTIONS>;

  /*-------------------------------------------------------------------------------
  Enumerations & Literals
  -------------------------------------------------------------------------------*/

  /**
   *  Possible number of slots that an animation sequence can be registered to
   */
  enum Registry : uint8_t
  {
    SLOT_0,
    SLOT_1,
    SLOT_2,
    SLOT_3,
    SLOT_4,

    NUM_OPTIONS
  };


  enum class AnimationType : uint8_t
  {
    DEFAULT,
    FLAME,
    SINEWAVE,

    NUM_OPTIONS
  };

  /*-------------------------------------------------------------------------------
  Structures
  -------------------------------------------------------------------------------*/
  struct AnimationData_Default
  {
  };


  struct AnimationData_Flame
  {
    size_t updateRate;
    size_t baseOutput;
    size_t modulus;
  };


  struct AnimationData_SineWave
  {
    size_t updateRate;
    size_t step;
  };


  union AnimationData
  {
    AnimationData_Default dflt;
    AnimationData_Flame flame;
    AnimationData_SineWave sinewave;
  };



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

    AnimationType type;
    AnimationData data;

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
    Registry currentAnimation;

    AnimationCB *defaultAnimation;
    std::array<AnimationSet*, Registry::NUM_OPTIONS> slots;
  };
}  // namespace Luminary::Routine

#endif  /* !LUMINARY_ROUTINE_TYPES_HPP */
