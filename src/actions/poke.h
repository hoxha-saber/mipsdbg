#ifndef POKE_H
#define POKE_H

#include "action.h"
class PokeAction : public Action {
    uint32_t addr;
    uint32_t val;
    public:
    PokeAction(uint32_t x, uint32_t y);
    void Execute(MIPS::Debugger &dbg) override;
};

#endif