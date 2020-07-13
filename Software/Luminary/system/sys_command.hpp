/********************************************************************************
 *  File Name:
 *    sys_command.hpp
 *
 *  Description:
 *    System level commands that can be invoked on the Luminary network
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_SYSTEM_COMMANDS_HPP
#define LUMINARY_SYSTEM_COMMANDS_HPP

/* RF24 Includes */
#include <RF24Node/common>

/* Luminary Includes */
#include <Luminary/routines/types.hpp>

namespace Luminary::System
{
  /**
   *  Sets the animation that should be running on all nodes in the network
   *
   *  @param[in]  animationID     The registry slot id for the desired animation
   *  @return void
   */
  void setGlobalAnimation( const Routine::Registry animationID );

  /**
   *  Sets the animation that should be running on a specific node in the network
   *
   *  @param[in]  address         Address of the node to set
   *  @param[in]  animationID     The registry slot id for the desired animation
   *  @return void
   */
  void setNodeAnimation( const RF24::LogicalAddress address, const Routine::Registry animationID );

}  // namespace Luminary::System

#endif  /* !LUMINARY_SYSTEM_COMMANDS_HPP */
