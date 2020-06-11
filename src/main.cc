#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

#include <cstdint>

#include <unistd.h>

#include "compute/ram.h"
#include "compute/bus.h"
#include "compute/cpu.h"

#include "dbg/debug.h"

#include "ncurses.h"


uint32_t readNum(std::istream & in) {
  std::string n_str;

  in >> n_str;
  std::stringstream n_ss (n_str);

  bool isDec = !(n_str[0] == '0' && n_str[1] == 'x') && !(n_str[1] == '0' && n_str[2] == 'x');

  long int x;
  n_ss >> ( (isDec) ? std::dec : std::hex ) >> x;

  return x;
}

void init_colors() {
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_RED);
}


int main(int argc, char const *argv[]) {

  // Check arguments
  if (argc < 2 || argc > 4) {
    std::cerr
      << "Usage: ./mipsdbg <filename> [--twoints] [--debug]"
      << std::endl
      << std::endl
      << "  By default, mipsdbg operates in `mips.array` mode."    << std::endl
      << "  To switch to `mips.twoints` mode, pass in [--twoints]" << std::endl
      << std::endl
      << "    --twoints : operate in `mips.twoints` mode" << std::endl
      << "    --debug   : enable interactive debug mode"  << std::endl
      << std::endl;
    return -1;
  }

  std::string filename;
  bool use_debug_mode = false;
  bool use_twoints = false;
  bool use_cin = false;
  for (int i = 1; i < argc; i++) {
    std::string arg = string(argv[i]);

    if (arg == "--twoints") use_twoints = true;
    if (arg == "--debug" ) use_debug_mode = true;
    if (arg == "--cin") use_cin = true;

    if (i == 1) filename = arg;
  }

  //--------------------------------- SETUP ---------------------------------//

  // Setup and connect up System
  MIPS::RAM ram;
  MIPS::BUS bus (ram);
  MIPS::CPU cpu (bus);

  // Open file
  std::ifstream f (filename, std::ifstream::binary);
  if (!f.is_open() && !use_cin) {
    endwin();
    std::cerr << "Cannot open file `" << filename << "`" << std::endl;
    return -1;
  }

  std::istream &bin = f;

  // Insert executable into virtual memory

  uint32_t memaddr = 0x0; // base memaddr

  char word[4];
  for (;;) {
    bin.read(word, 4);

    if(bin.eof()) break;

    // Reverse endiannessss
    char x;
    x = word[0];
    word[0] = word[3];
    word[3] = x;
    x = word[1];
    word[1] = word[2];
    word[2] = x;

    // Store it in RAM (with some funky casting)
    ram.store(memaddr, *(uint32_t *)word );

    memaddr += 4;
  }

  ram.setEndAddr(memaddr + 4); // mark where the executable ends;

  // Accept user input
  if (use_twoints) {
    // Let user input 2 integers
    std::cerr << "Enter value for Register 1: ";
    cpu.setRegister(1, readNum(std::cin));
    std::cerr << "Enter value for Register 2: ";
    cpu.setRegister(2, readNum(std::cin));
  } else {
    // Let user enter Array of values
    std::cerr << "Enter length of Array: ";
    int arr_length = readNum(std::cin);
    cpu.setRegister(2, arr_length); // $2 = length of array

    // Start populating the array 16 words after the end of the program
    // this was chosen relatively arbitrarilly...
    memaddr += 0x10;

    cpu.setRegister(1, memaddr); // $1 = Pointer to base of array

    for (int i = 0; i < arr_length; i++) {
      std::cerr << "Enter Array element " << i << ": ";
      ram.store(memaddr, readNum(std::cin));
      memaddr += 4;
    }
  }

  // If this program is running interactively, clear cin before starting cpu
  //  emulation
  bool isTTY = isatty(fileno(stdin));
  if (isTTY) { std::string dummy; getline(std::cin, dummy); }


  std::cerr << std::endl;


  // Start CPU execution
  MIPS::Debugger debugger (cpu, ram, bus);
  Interpreter cli;
  try {
    std::cerr << "Starting CPU..." << std::endl;
    initscr();
    start_color();
    init_colors();
    raw();
    cbreak();
    noecho();
    do {

      if (use_debug_mode && debugger.isBreakpoint(cpu.getPC())) {
        while (debugger.isSuspended()){
          debugger.render();
          auto p = cli.GetAction();
          p->Execute(debugger);
        }
      }

      // Execute cpu cycle
      cpu.do_instr();

      // std::cout << bus.getOutput();

    } while (cpu.stillExecuting());
    endwin();
    std::cerr
      << "Execution completed successfully!"
      << std::endl;
    // debugger.printCPUState();

  } catch (const std::string & msg) {
    endwin();
    std::cerr
      << "ERROR : "
      << msg
      << std::endl;
    // debugger.printCPUState();
    return -1;
  }
  return 0;
}