/********************************************************************************
 *  File Name:
 *    serial.hpp
 *
 *  Description:
 *    Luminary interface for the Serial hardware
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_SERIAL_HPP
#define LUMINARY_SERIAL_HPP

/* STL Includes */
#include <cstdint>

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/serial>

namespace Luminary::Hardware::Serial
{
  static constexpr Chimera::Serial::Channel HWChannel = Chimera::Serial::Channel::SERIAL1;

  /**
   *  Instantiates and initializes the serial driver for Luminary. Given that
   *  there is only one serial output, this function is hardcoded to initialize
   *  just that peripheral.
   *
   *  @return Chimera::Status_t
   */
  Chimera::Status_t configureDriver();

}  // namespace Luminary::Hardware::Serial

#endif  /* !LUMINARY_SERIAL_HPP */
