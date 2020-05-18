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
#include <Luminary/model/mdl_common.hpp>
#include <Luminary/system/sys_main.hpp>
#include <Luminary/networking/net_main.hpp>
#include <Luminary/hardware/hwm_main.hpp>


int main()
{
  ChimeraInit();

  /*-------------------------------------------------
  Initialize module memory
  -------------------------------------------------*/
  Luminary::Model::initializeModule();

  /*-------------------------------------------------
  Start up the system threads in the proper order
  -------------------------------------------------*/
  Chimera::Threading::Thread hwmMain;
  hwmMain.initialize( Luminary::Hardware::MainThread, nullptr, Luminary::Hardware::MainThreadPriority, 1024, "HWM_MAIN" );
  hwmMain.start();

  // Chimera::Threading::Thread sysMain;
  // sysMain.initialize( Luminary::System::MainThread, nullptr, Chimera::Threading::Priority::LEVEL_2, 1024, "SYS_MAIN" );
  // sysMain.start();

  /*-------------------------------------------------
  Start the scheduler, which should never return
  -------------------------------------------------*/
  Chimera::Threading::startScheduler();
  return -1;
}