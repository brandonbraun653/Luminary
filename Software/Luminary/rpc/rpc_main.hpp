/********************************************************************************
 *  File Name:
 *    rpc_main.hpp
 *
 *  Description:
 *    RPC main thread
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

#pragma once
#ifndef LUMINARY_RPC_MAIN_HPP
#define LUMINARY_RPC_MAIN_HPP

/* STL Includes */
#include <cstddef>

/* Chimera Includes */
#include <Chimera/thread>

namespace Luminary::RPC
{
  static constexpr auto MainThreadPriority     = Chimera::Threading::Priority::LEVEL_3;
  static constexpr size_t MainThreadUpdateRate = 50;
  static constexpr size_t MainThreadStackSize  = 2048;

  /**
   *  Initializes the entire RPC module
   *  @return void
   */
  void initializeModule();

  /**
   *  Primary thread of execution for RPC related tasks
   *
   *  @param[in]  argument    Not used
   *  @return void
   */
  void MainThread( void *argument );

}  // namespace Luminary::RPC

#endif  /* !LUMINARY_RPC_MAIN_HPP */
