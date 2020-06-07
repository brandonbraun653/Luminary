/********************************************************************************
 *  File Name:
 *    boot_config.hpp
 *
 *  Description:
 *    Boot configuration interface for reading hardware ID settings
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_BOOT_CONFIGURATION_HPP
#define LUMINARY_BOOT_CONFIGURATION_HPP

/* Chimera Includes */
#include <Chimera/common>

/* RF24 Includes */
#include <RF24Node/common>


namespace Luminary::Hardware::Boot
{
  /**
   *  Reads the boot configuration GPIO pins to determine various
   *  device settings.
   *
   *  @return Chimera::Status_t
   */
  Chimera::Status_t readConfiguration();

  /**
   *  Gets the node address for this device as configured by hardware GPIO
   *
   *  @return RF24::LogicalAddress
   */
  RF24::LogicalAddress getNodeAddress();

}  // namespace Luminary::Hardware

#endif  /* !LUMINARY_BOOT_CONFIGURATION_HPP */
