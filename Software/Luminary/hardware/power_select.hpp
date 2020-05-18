/********************************************************************************
 *  File Name:
 *    power_select.hpp
 *
 *  Description:
 *    Power selction driver interface
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_POWER_SELECT_HPP
#define LUMINARY_POWER_SELECT_HPP

/* STL Includes */
#include <cstdint>

/* Chimera Includes */
#include <Chimera/common>

namespace Luminary::Hardware::Power
{
  /**
   *  Controllable device power channels on the Luminary board
   */
  enum Channel : uint8_t
  {
    RF24_RADIO,
    EXTERNAL_FLASH,

    NUM_OPTIONS,
    INVALID
  };

  /**
   *  Initializes the memory associated with this module
   *  @return void
   */
  void initialize();

  /**
   *  Turns the GPIO associated with the particular channel on/off.
   *  The interaction is thread-safe.
   *
   *  @param[in]  channel   Which channel to interact with
   *  @param[in]  state     The state to turn to: True==HI, False==LO
   *  @return void
   */
  Chimera::Status_t setPowerState( const Channel channel, const bool state );

}  // namespace Luminary::Hardware::Power

#endif  /* !LUMINARY_POWER_SELECT_HPP */
