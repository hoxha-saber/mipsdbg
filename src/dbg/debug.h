#ifndef DEBUG_H_
#define DEBUG_H_

#include "../compute/bus.h"
#include "../compute/ram.h"
#include "../compute/cpu.h"

#include <map>
#include <set>
#include "ncurses.h"

#include "interpreter.h"

using namespace std;

namespace MIPS {
  class Debugger {
  private:
    CPU &cpu;
    RAM &ram;
    BUS &bus;
    WINDOW *codeWin;
    WINDOW *stackWin;
    

    bool cycleStep; // If we want to step cycle-by-cycle
    bool step;      // If we want to step instr-by-instr

    set<uint32_t> breakpoints; // Which addresses to break on
    set<uint32_t> watch;       // Which addresses to watch

    void drawProgram();
    void drawStack();
    void drawMemToWin(WINDOW* win, uint32_t addr);

  public:
    Debugger(CPU &cpu, RAM &ram, BUS &bus);
    ~Debugger();

    bool isBreakpoint(uint32_t addr);
    void setBreakpoint(uint32_t addr);
    void removeBreakpoint(uint32_t addr);

    bool isWatch(uint32_t addr);
    void setWatch(uint32_t addr);
    void removeWatch(uint32_t addr);

    bool isDebugCycle();
    bool isDebugStep();

    void render();

    bool toggleDebugMode();
  };
}

#endif