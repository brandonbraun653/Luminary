/********************************************************************************
 *  File Name:
 *    log_main.hpp
 *
 *  Description:
 *    Logging interface for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_LOGGING_HPP
#define LUMINARY_LOGGING_HPP

/* STL Includes */
#include <cstddef>

/* Chimera Includes */
#include <Chimera/thread>

/* uLog Includes */
#include <uLog/ulog.hpp>

namespace Luminary::Logging
{
  static constexpr auto MainThreadPriority     = Chimera::Threading::Priority::LEVEL_2;
  static constexpr size_t MainThreadUpdateRate = 500;
  static constexpr size_t MainThreadStackSize  = 1024;

  void initializeModule();

  void MainThread( void *argument );

  uLog::SinkHandle getSystemLogger();
}  // namespace Luminary::Logging

#endif  /* !LUMINARY_LOGGING_HPP */
