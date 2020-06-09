#include "poke.h"

PokeAction::PokeAction(uint32_t x, uint32_t y) : addr{x}, val{y} {}

void PokeAction::Execute(MIPS::Debugger &dbg) {
    dbg.pokeMem(addr, val);
}