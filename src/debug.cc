#include "debug.h"

#include <iostream>
#include <iomanip>
#include <sstream>

#include <cstdint>

#include <vector>
#include <map>

#include "bus.h"
#include "ram.h"
#include "cpu.h"
#include "disasm.h"


using namespace std;
using namespace MIPS;

template <typename T>
string toHex(T const& x) {
  ostringstream out;
  out << "0x" << setfill('0') << setw(8) << hex << right << x;
  return out.str();
}

Debugger::Debugger(CPU &cpu, RAM &ram, BUS &bus)
: cpu(cpu), ram(ram), bus(bus)
{

  cycleStep = false;

  step = false;

  // Break at the start of the program
  breakpoints.insert(0x00000000);
  codeWin = newwin(LINES/3, COLS, 0, 0);
  stackWin = newwin(LINES/3, COLS, LINES/3, 0);
  box(codeWin, 0, 0);
  box(stackWin, 0, 0);
}

Debugger::~Debugger() {
  delwin(stackWin);
  delwin(codeWin);
}


bool Debugger::isBreakpoint(uint32_t addr){
  return breakpoints.count(addr) == 0;
}

void Debugger::setBreakpoint(uint32_t addr) {
  breakpoints.insert(addr);
}

void Debugger::removeBreakpoint(uint32_t addr) {
  breakpoints.erase(addr);
}

bool Debugger::isWatch(uint32_t addr){
  return watch.count(addr) == 0;
}

void Debugger::setWatch(uint32_t addr){
  watch.insert(addr);
}

void Debugger::removeWatch(uint32_t addr) {
  watch.erase(addr);
}

bool Debugger::isDebugCycle() {
  return cycleStep;
}

bool Debugger::isDebugStep() {
  return step;
}

bool Debugger::toggleDebugMode() {
  step = cycleStep;
  cycleStep = !cycleStep;
  return step;
}




