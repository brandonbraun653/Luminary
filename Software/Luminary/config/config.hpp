/********************************************************************************
 *  File Name:
 *    config.hpp
 *
 *  Description:
 *    Configuration options for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_CONFIG_HPP
#define LUMINARY_CONFIG_HPP

/* STL Includes */
#include <cstddef>

namespace Luminary
{
  static constexpr size_t STARTUP_DELAY_HWM_MAIN = 5;
  static constexpr size_t STARTUP_DELAY_SYS_MAIN = 1000;
  static constexpr size_t STARTUP_DELAY_NET_MAIN = 500;
  static constexpr size_t STARTUP_DELAY_RPC_MAIN = 100;
  static constexpr size_t STARTUP_DELAY_LOG_MAIN = 200;

}  // namespace Luminary

#endif  /* !LUMINARY_CONFIG_HPP */
