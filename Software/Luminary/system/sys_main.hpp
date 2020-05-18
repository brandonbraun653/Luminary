/********************************************************************************
 *  File Name:
 *    sys_main.hpp
 *
 *  Description:
 *    Main system thread for Luminary
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_MAIN_SYSTEM_THREAD_HPP
#define LUMINARY_MAIN_SYSTEM_THREAD_HPP

/* STL Includes */
#include <cstddef>

/* Chimera Includes */
#include <Chimera/thread>

namespace Luminary::System
{
  static constexpr auto MainThreadPriority     = Chimera::Threading::Priority::LEVEL_3;
  static constexpr size_t MainThreadUpdateRate = 50;
  static constexpr size_t MainThreadStackSize  = 1024;

  /**
   *  Initializes the entire System module
   *  @return void
   */
  void initializeModule();

  /**
   *  Primary thread of execution for System related tasks
   *
   *  @param[in]  argument    Not used
   *  @return void
   */
  void MainThread( void *argument );
}

#endif  /* !LUMINARY_MAIN_SYSTEM_THREAD_HPP */
