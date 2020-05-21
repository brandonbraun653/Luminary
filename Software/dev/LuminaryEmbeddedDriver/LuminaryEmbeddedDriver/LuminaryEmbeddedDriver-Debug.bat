@echo off
REM Run this file to build the project outside of the IDE.
REM WARNING: if using a different machine, copy the .rsp files together with this script.
echo hwm_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/hwm_main.gcc.rsp" || exit 1
echo power_select.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/power_select.gcc.rsp" || exit 1
echo status_led.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/status_led.gcc.rsp" || exit 1
echo log_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/log_main.gcc.rsp" || exit 1
echo luminary_entry.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/luminary_entry.gcc.rsp" || exit 1
echo mdl_common.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/mdl_common.gcc.rsp" || exit 1
echo net_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/net_main.gcc.rsp" || exit 1
echo sys_main.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/sys_main.gcc.rsp" || exit 1
echo FastSemihosting.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/FastSemihosting.gcc.rsp" || exit 1
echo SamplingProfiler.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/SamplingProfiler.gcc.rsp" || exit 1
echo InstrumentingProfiler.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/InstrumentingProfiler.gcc.rsp" || exit 1
echo TestResourceManager.cpp
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @"VisualGDB/Debug/TestResourceManager.gcc.rsp" || exit 1
echo ProfilerRTOS_FreeRTOS.c
c:\sysgcc\arm-eabi\bin\arm-none-eabi-gcc.exe @"VisualGDB/Debug/ProfilerRTOS_FreeRTOS.gcc.rsp" || exit 1
echo Linking ../VisualGDB/Debug/LuminaryEmbeddedDriver...
c:\sysgcc\arm-eabi\bin\arm-none-eabi-g++.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.link.rsp || exit 1
c:\sysgcc\arm-eabi\bin\arm-none-eabi-objcopy.exe @../VisualGDB/Debug/LuminaryEmbeddedDriver.mkbin.rsp || exit 1
