# ANSI GMMKV2 96% Layout

## How to build (notes for future Tim who forgot how)

1. Open the program QMK_MSYS (installed), it just opens a command window, and run the command `qmk compile`. This outputs a new bin file in the root of the git project.
2. Open the program QMK Toolbox (loose exe), direct it at the bin file you just made.
3. Press `FN + \` on the keyboard to put it in flash mode.
4. The toolbox will log that it noticed the keyboard ready for flashing.
5. Press "Flash" and wait for it complete, then "Exit DFU" to reset the keyboard back into it's normal state.
