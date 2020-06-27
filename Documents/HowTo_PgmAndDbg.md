# How To Program and Debug Luminary

Luminary uses a standard JTAG connection to connect via SWD to the microcontroller with OpenOCD and GDB.
Here are a few instructions to get started with that.

1. Open two terminals. One will run the OpenOCD server, the other will be for GDB.
2. In the first terminal start OpenOCD using the following command:

   openocd.exe -f openocd\scripts\interface\stlink.cfg -f openocd\scripts\target\stm32l4x.cfg -s openocd\scripts

   - The '-f' flag is to specify configuration files. The '-s' flag tells OpenOCD where common scripts are.
   - This will start a GDB server on port 3333 which you can connect to

3. In the second terminal open GDB using the following sequence of commands:

     - arm-none-eabi-gdb
     - file luminary.elf
     - target remote localhost:3333
     - monitor reset halt
     - load

4. In the third terminal you can build Luminary using:

     - bjam luminary -j8 -a -q debug
