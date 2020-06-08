cmake_minimum_required(VERSION 3.10.2)
project(mipsdbg)
set(CMAKE_CXX_STANDARD 14)
find_package(Curses REQUIRED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${mipsdbg_SOURCE_DIR}/bin)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(mipsdbg src/main.cc
                       src/compute/bus.cc
                       src/compute/cpu.cc
                       src/compute/ram.cc
                       src/oops.cc
                       src/dbg/disasm.cc
                       src/dbg/debug.cc
                       src/dbg/interpreter.cc
                       src/scan.cc
                       src/actions/action.cc
                       src/actions/breakpoint.cc
                       src/actions/peek.cc
                       src/actions/poke.cc
                       src/actions/next.cc
                       src/actions/run.cc
                       src/actions/print.cc
                       src/actions/watch.cc)
target_link_libraries(mipsdbg ${CURSES_LIBRARIES})
target_compile_options(mipsdbg PRIVATE -g -Wall -std=c++14)
