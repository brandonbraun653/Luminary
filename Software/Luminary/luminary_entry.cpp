/********************************************************************************
 *  File Name:
 *    luminary_entry.cpp
 *
 *  Description:
 *    Startup code for Luminary project
 *
 *  2020 | Brandon Braun | brandonbraun653@gmail.com
 *******************************************************************************/

/* Chimera Includes */
#include <Chimera/common>
#include <Chimera/thread>

/* Luminary Includes */
#include <Luminary/hardware/hwm_main.hpp>
#include <Luminary/logging/log_main.hpp>
#include <Luminary/model/mdl_common.hpp>
#include <Luminary/networking/net_main.hpp>
#include <Luminary/system/sys_main.hpp>

static void systemPowerUp();

int main()
{
  ChimeraInit();
  systemPowerUp();

  /*-------------------------------------------------
  Start up the system threads in the proper order
  -------------------------------------------------*/
  /* clang-format off */
  Chimera::Threading::Thread hwmMain;
  hwmMain.initialize( Luminary::Hardware::MainThread,
                      nullptr,
                      Luminary::Hardware::MainThreadPriority,
                      Luminary::Hardware::MainThreadStackSize,
                      "HWM_MAIN" );
  hwmMain.start();

  Chimera::Threading::Thread sysMain;
  sysMain.initialize( Luminary::System::MainThread,
                      nullptr,
                      Luminary::System::MainThreadPriority,
                      Luminary::System::MainThreadStackSize,
                      "SYS_MAIN" );
  sysMain.start();

  Chimera::Threading::Thread netMain;
  netMain.initialize( Luminary::Network::MainThread,
                      nullptr,
                      Luminary::Network::MainThreadPriority,
                      Luminary::Network::MainThreadStackSize,
                      "NET_MAIN" );
  netMain.start();

  Chimera::Threading::Thread logMain;
  logMain.initialize( Luminary::Logging::MainThread,
                      nullptr,
                      Luminary::Logging::MainThreadPriority,
                      Luminary::Logging::MainThreadStackSize,
                      "LOG_MAIN" );
  logMain.start();
  /* clang-format on */

  /*-------------------------------------------------
  Start the scheduler, which should never return
  -------------------------------------------------*/
  Chimera::Threading::startScheduler();
  return -1;
}


void systemPowerUp()
{
  /*-------------------------------------------------
  Initialize the system modules that don't require the scheduler in the proper order:

    1. Model data   -- Required for default settings, data, etc used by other drivers
    2. HWM Drivers  -- Gets the hardware level drivers and memory ready
    3. Anything else
  -------------------------------------------------*/
  Luminary::Model::initializeModule();
  Luminary::Hardware::initializeModule();
  Luminary::System::initializeModule();
  Luminary::Logging::initializeModule();
  Luminary::Network::initializeModule();
}