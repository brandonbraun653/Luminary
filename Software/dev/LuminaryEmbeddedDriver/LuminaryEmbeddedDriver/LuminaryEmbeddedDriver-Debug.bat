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
echo rcp_responder.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rcp_responder.gcc.rsp" || exit 1
echo rpc_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rpc_main.gcc.rsp" || exit 1
echo rpc_parser.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/_3_/Luminary/rpc/rpc_parser.gcc.rsp" || exit 1
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
