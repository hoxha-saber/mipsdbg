#include "poke.h"

PokeAction::PokeAction(uint32_t x, uint32_t y, bool isReg) : addr{x}, val{y} {}

void PokeAction::Execute(MIPS::Debugger &dbg) {
    is_reg ? dbg.pokeMem(addr, val) : dbg.pokeReg(addr, val);
}