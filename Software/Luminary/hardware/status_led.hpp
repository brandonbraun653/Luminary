/********************************************************************************
 *  File Name:
 *    status_led.hpp
 *
 *  Description:
 *    Status LED driver
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_STATUS_LED_HPP
#define LUMINARY_STATUS_LED_HPP

/* Chimera Includes */
#include <Chimera/common>

namespace Luminary::Hardware::StatusLED
{
  /*-------------------------------------------------------------------------------
  Enumerations
  -------------------------------------------------------------------------------*/
  enum class BlinkPattern : uint8_t
  {
    HEARTBEAT,              /**< Everything is ok and system is operational */
    FAILED_CONFIG,          /**< Hardware configuration is bad */
    NETWORK_DISCONNECTED,   /**< Network connection has been lost */
    NETWORK_CONNECTING,     /**< Network connection in progress */
    NETWORK_CONNECTED,      /**< Network connection success/restored */

    NUM_OPTIONS
  };

  /*-------------------------------------------------------------------------------
  Public Functions
  -------------------------------------------------------------------------------*/
  /**
   *  Initializes the status LED driver
   *
   *  @return Chimera::CommonStatusCodes::OK
   */
  Chimera::Status_t initialize();

  /**
   *  Sets the led output state, ON/OFF
   *
   *  @param[in]  state   ON==true, OFF==false
   *  @return void
   */
  void setState( const bool state );

  /**
   *  Toggles the status led state
   *  @return void
   */
  void toggleState();

  /**
   *  Special method that flashes the status LED in a specific
   *  sequency to indicate the board is booting up.
   *
   *  @return void
   */
  void executeBootFlashSequence();

  /**
   *  Blinks the LED at a predetermined rate to signify that
   *  the board is still alive.
   *
   *  @return void
   */
  void runStatusProcessing();

  /**
   *  Updates the status led with the given blinking pattern
   *
   *  @param[in]  pattern     The pattern to use
   *  @return void
   */
  void updateStatus( const BlinkPattern pattern );

}  // namespace Luminary::Hardware

#endif  /* !LUMINARY_STATUS_LED_HPP */
