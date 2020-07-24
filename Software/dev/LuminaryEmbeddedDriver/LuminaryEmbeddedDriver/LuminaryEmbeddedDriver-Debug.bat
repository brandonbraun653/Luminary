@echo off
REM Run this file to build the project outside of the IDE.
REM WARNING: if using a different machine, copy the .rsp files together with this script.
echo boot_config.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/hardware/boot_config.gcc.rsp" || exit 1
echo hwm_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/hardware/hwm_main.gcc.rsp" || exit 1
echo power_select.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/hardware/power_select.gcc.rsp" || exit 1
echo pwm_output.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/hardware/pwm_output.gcc.rsp" || exit 1
echo hwm_serial.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/hardware/hwm_serial.gcc.rsp" || exit 1
echo status_led.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/hardware/status_led.gcc.rsp" || exit 1
echo log_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/logging/log_main.gcc.rsp" || exit 1
echo luminary_entry.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/luminary_entry.gcc.rsp" || exit 1
echo mdl_common.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/model/mdl_common.gcc.rsp" || exit 1
echo mdl_observables.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/model/mdl_observables.gcc.rsp" || exit 1
echo net_connect.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/networking/net_connect.gcc.rsp" || exit 1
echo net_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/networking/net_main.gcc.rsp" || exit 1
echo animation_breath.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/routines/animation_breath.gcc.rsp" || exit 1
echo animation_default.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/routines/animation_default.gcc.rsp" || exit 1
echo animation_flame.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/routines/animation_flame.gcc.rsp" || exit 1
echo animation_sine_wave.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/routines/animation_sine_wave.gcc.rsp" || exit 1
echo animation_twinkle.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/routines/animation_twinkle.gcc.rsp" || exit 1
echo processor.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/routines/processor.gcc.rsp" || exit 1
echo rcp_responder.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rcp_responder.gcc.rsp" || exit 1
echo rpc_action_animation.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rpc_action_animation.gcc.rsp" || exit 1
echo rpc_action_brightness.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rpc_action_brightness.gcc.rsp" || exit 1
echo rpc_action_output_state.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rpc_action_output_state.gcc.rsp" || exit 1
echo rpc_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rpc_main.gcc.rsp" || exit 1
echo rpc_parser.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rpc_parser.gcc.rsp" || exit 1
echo sys_command.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/system/sys_command.gcc.rsp" || exit 1
echo sys_event.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/system/sys_event.gcc.rsp" || exit 1
echo sys_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/system/sys_main.gcc.rsp" || exit 1
echo FastSemihosting.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/__LOCALAPPDATA__/VisualGDB/EmbeddedEFPs/Profiler/FastSemihosting.gcc.rsp" || exit 1
echo SamplingProfiler.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/__LOCALAPPDATA__/VisualGDB/EmbeddedEFPs/Profiler/SamplingProfiler.gcc.rsp" || exit 1
echo InstrumentingProfiler.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/__LOCALAPPDATA__/VisualGDB/EmbeddedEFPs/Profiler/InstrumentingProfiler.gcc.rsp" || exit 1
echo TestResourceManager.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/__LOCALAPPDATA__/VisualGDB/EmbeddedEFPs/Profiler/TestResourceManager.gcc.rsp" || exit 1
echo ProfilerRTOS_FreeRTOS.c
c:\sysgcc\arm-eabi\bin\arm-none-eabi-gcc.exe @"VisualGDB/Debug/__LOCALAPPDATA__/VisualGDB/EmbeddedEFPs/Profiler/ProfilerRTOS_FreeRTOS.gcc.rsp" || exit 1
echo Linking ../VisualGDB/Debug/LuminaryEmbeddedDriver...
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.link.rsp || exit 1
c:\sysgcc\arm-eabi\bin\arm-none-eabi-objcopy.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.mkbin.rsp || exit 1
c:\sysgcc\arm-eabi\bin\arm-none-eabi-objcopy.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.mkihex.rsp || exit 1
