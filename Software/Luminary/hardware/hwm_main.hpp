/********************************************************************************
 *  File Name:
 *    hwm_main.hpp
 *
 *  Description:
 *    Hardware management thread for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_HARDWARE_THREAD_HPP
#define LUMINARY_HARDWARE_THREAD_HPP

/* STL Includes */
#include <cstddef>

/* Chimera Includes */
#include <Chimera/thread>

namespace Luminary::Hardware
{
  /*-------------------------------------------------
  Use the highest priority to ensure that HWM tasks get time to execute.
  -------------------------------------------------*/
  static constexpr auto MainThreadPriority     = Chimera::Threading::Priority::LEVEL_4;
  static constexpr size_t MainThreadUpdateRate = 5;
  static constexpr size_t MainThreadStackSize  = 2048;

  /**
   *  Initializes the entire hardware module
   *  @return void
   */
  void initializeModule();

  /**
   *  Primary thread of execution for hardware related tasks
   *
   *  @param[in]  argument    Not used
   *  @return void
   */
  void MainThread( void *argument );
}

#endif  /* !LUMINARY_HARDWARE_THREAD_HPP */
