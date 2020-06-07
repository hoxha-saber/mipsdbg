cmake_minimum_required(VERSION 3.10.2)
project(mipsdbg)
set(CMAKE_CXX_STANDARD 14)
find_package(Curses REQUIRED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${mipsdbg_SOURCE_DIR}/bin)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(mipsdbg src/main.cc
                       src/bus.cc
                       src/cpu.cc
                       src/ram.cc
                       src/error.cc
                       src/disasm.cc
                       src/debug.cc
                       src/interpreter.cc
                       src/scan.cc
                       src/action.cc)
target_link_libraries(mipsdbg ${CURSES_LIBRARIES})
target_compile_options(mipsdbg PRIVATE -g -Wall -std=c++14)
