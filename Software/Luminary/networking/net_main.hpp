/********************************************************************************
 *  File Name:
 *    net_main.hpp
 *
 *  Description:
 *    Networking main thread for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_NETWORKING_THREAD_HPP
#define LUMINARY_NETWORKING_THREAD_HPP

/* STL Includes */
#include <cstddef>

/* Chimera Includes */
#include <Chimera/thread>

namespace Luminary::Network
{
  static constexpr auto MainThreadPriority     = Chimera::Threading::Priority::LEVEL_4;
  static constexpr size_t MainThreadUpdateRate = 10;
  static constexpr size_t MainThreadStackSize  = 1024;

  /**
   *  Initializes the entire Network module
   *  @return void
   */
  void initializeModule();

  /**
   *  Primary thread of execution for Networking related tasks
   *
   *  @param[in]  argument    Not used
   *  @return void
   */
  void MainThread( void *argument );
}

#endif  /* !LUMINARY_NETWORKING_THREAD_HPP */
