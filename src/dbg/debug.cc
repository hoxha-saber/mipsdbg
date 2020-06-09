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

void Debugger::drawMemToWin(WINDOW *win, uint32_t addr) {
  box(win, 0, 0);
  for (int i = 1; i < (LINES / 3) - 1; ++i) {
    std::string line = toHex(addr) + ":" + "     " + disasm(ram.load(addr));
    wmove(win, i, 1);
    if (isBreakpoint(addr)) {
      wattron(win, COLOR_PAIR(2));
    }
    wprintw(win, line.c_str());
    wattroff(win, COLOR_PAIR(2));
    addr +=4;
  }
  wrefresh(win);
}

void Debugger::drawProgram() {
  // Need to figure out better way to print the code when stepping
  drawMemToWin(codeWin, cpu.getPC());
}

void Debugger::drawStack() {
  // Print the top of stack
  drawMemToWin(stackWin, cpu.getRegister(30));
}

void Debugger::render() {
  werase(codeWin);
  werase(stackWin);
  drawProgram();
  drawStack();
}

void Debugger::pokeMem(uint32_t addr, uint32_t val) {
  ram.store(addr, val);
}




