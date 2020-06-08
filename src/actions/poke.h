#ifndef POKE_H
#define POKE_H

#include "action.h"
class PokeAction : public Action {
    uint32_t addr;
    public:
    PokeAction(uint32_t x);
    void Execute(MIPS::Debugger &dbg) override;
};

#endif