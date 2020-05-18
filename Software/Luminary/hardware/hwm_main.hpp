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

namespace Luminary::Hardware
{
  /*-------------------------------------------------
  Use the highest priority to ensure that HWM tasks get time to execute.
  -------------------------------------------------*/
  static constexpr auto MainThreadPriority = Chimera::Threading::Priority::LEVEL_5;
  static constexpr size_t MainThreadUpdateRate = 5;

  void MainThread( void *argument );
}

#endif  /* !LUMINARY_HARDWARE_THREAD_HPP */
