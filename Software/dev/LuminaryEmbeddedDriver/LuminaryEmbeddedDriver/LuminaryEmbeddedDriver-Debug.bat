@echo off
REM Run this file to build the project outside of the IDE.
REM WARNING: if using a different machine, copy the .rsp files together with this script.
echo boot_config.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/boot_config.gcc.rsp" || exit 1
echo hwm_main.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/hwm_main.gcc.rsp" || exit 1
echo power_select.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/power_select.gcc.rsp" || exit 1
echo pwm_output.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/pwm_output.gcc.rsp" || exit 1
echo hwm_serial.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/hwm_serial.gcc.rsp" || exit 1
echo status_led.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/status_led.gcc.rsp" || exit 1
echo log_main.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/log_main.gcc.rsp" || exit 1
echo luminary_entry.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/luminary_entry.gcc.rsp" || exit 1
echo mdl_common.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/mdl_common.gcc.rsp" || exit 1
echo mdl_observables.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/mdl_observables.gcc.rsp" || exit 1
echo net_connect.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/net_connect.gcc.rsp" || exit 1
echo net_main.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/net_main.gcc.rsp" || exit 1
echo animation_default.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/animation_default.gcc.rsp" || exit 1
echo animation_flame.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/animation_flame.gcc.rsp" || exit 1
echo animation_sine_wave.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/animation_sine_wave.gcc.rsp" || exit 1
echo processor.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/processor.gcc.rsp" || exit 1
echo rcp_responder.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/rcp_responder.gcc.rsp" || exit 1
echo rpc_action_animation.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/rpc_action_animation.gcc.rsp" || exit 1
echo rpc_action_brightness.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/rpc_action_brightness.gcc.rsp" || exit 1
echo rpc_action_output_state.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/rpc_action_output_state.gcc.rsp" || exit 1
echo rpc_main.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/rpc_main.gcc.rsp" || exit 1
echo rpc_parser.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/rpc_parser.gcc.rsp" || exit 1
echo sys_command.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/sys_command.gcc.rsp" || exit 1
echo sys_event.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/sys_event.gcc.rsp" || exit 1
echo sys_main.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/sys_main.gcc.rsp" || exit 1
echo FastSemihosting.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/FastSemihosting.gcc.rsp" || exit 1
echo SamplingProfiler.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/SamplingProfiler.gcc.rsp" || exit 1
echo InstrumentingProfiler.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/InstrumentingProfiler.gcc.rsp" || exit 1
echo TestResourceManager.cpp
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/TestResourceManager.gcc.rsp" || exit 1
echo ProfilerRTOS_FreeRTOS.c
c:\SysGCC\arm-eabi\bin\arm-none-eabi-gcc.exe @"VisualGDB/Debug/ProfilerRTOS_FreeRTOS.gcc.rsp" || exit 1
echo Linking ../VisualGDB/Debug/LuminaryEmbeddedDriver...
c:\SysGCC\arm-eabi\bin\arm-none-eabi-g++.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.link.rsp || exit 1
c:\SysGCC\arm-eabi\bin\arm-none-eabi-objcopy.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.mkbin.rsp || exit 1
c:\SysGCC\arm-eabi\bin\arm-none-eabi-objcopy.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.mkihex.rsp || exit 1
