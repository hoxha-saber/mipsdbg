#include "ram.h"
#include "../oops.h"

#include <cstdint>
#include <sstream>

MIPS::RAM::RAM () {}
MIPS::RAM::~RAM () { for (auto entry : mem) delete [] entry.second; }

void MIPS::RAM::store(uint32_t memaddr, uint32_t word) {
  if (memaddr % 4 != 0) {
    std::stringstream a; a << memaddr;
    MIPS::error("Unaligned Access - Cannot Store to 0x" + a.str());
  }

  uint16_t page   = (memaddr >> 16) & 0xFFFF;
  uint16_t offset =  memaddr        & 0xFFFF;

  if (mem.count(page) == 0) {
    mem[page] = new uint32_t [(0xFFFF + 1) / 4](); // word addressable
  }

  mem[page][offset / 4] = word;
}

uint32_t MIPS::RAM::load(uint32_t memaddr) {
  if (memaddr % 4 != 0) {
    std::stringstream a; a << memaddr;
    MIPS::error("Unaligned Access - Cannot Store to 0x" + a.str());
  }

  uint16_t page   = (memaddr >> 16) & 0xFFFF;
  uint16_t offset =  memaddr        & 0xFFFF;

  if (mem.count(page) == 0) {
    mem[page] = new uint32_t [(0xFFFF + 1) / 4](); // word addressable
  }

  return mem[page][offset / 4];
}

void MIPS::RAM::setEndAddr(uint32_t memaddr) {
  endaddr = memaddr;
}

uint32_t MIPS::RAM::getEndAddr() {
  return endaddr;
}
