/********************************************************************************
 *  File Name:
 *    sys_event.hpp
 *
 *  Description:
 *    System event interface
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_SYSTEM_EVENT_HPP
#define LUMINARY_SYSTEM_EVENT_HPP

/* STL Includes */
#include <array>

/* include description */
#include <Luminary/networking/types.hpp>

namespace Luminary::System
{
  using EventHandler = void ( * )( const uint8_t msg, void *data );
  using EventCallbackList = std::array<EventHandler, Luminary::Network::MessageType::NUM_OPTIONS>;

  extern EventCallbackList eventCallbacks;


  void registerEventCallbacks();


  void changeAnimationHandler( const uint8_t msg, void *data );
  void changeBrightnessHandler( const uint8_t msg, void *data );

}  // namespace Luminary::System

#endif  /* !LUMINARY_SYSTEM_EVENT_HPP */
