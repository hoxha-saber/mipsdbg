# WORK IN PROGRESS

# mipsdbg
mipsdbg is a fully interactive debugger that runs on a subset of the MIPS machine language. It is similar to gdb -tui mode where you can examine where you are in your code and edit register and memory values.

## How to build
Simply run the setup script setup.sh to get started. You will see a new folder called bin, with the executable mipsdbg inside.

## How to run
The default mode for mipsdbg is emulator mode. In this mode, mipsdbg reads in an exectuable from a file and runs it, outputting the results of all 32, 32-bit general purpose registers at the end. Alternatively, you can use the "--debug" flag to run it debug mode. In this case, you can step through line by line while also being able to examine memory addresses and registers. A full list of all the commands will be outlined below.
