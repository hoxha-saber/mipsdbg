#ifndef PEEK_H
#define PEEK_H
#include "action.h"
class PeekAction : public Action {
    uint32_t addr;
    public:
    PeekAction(uint32_t x);
    void Execute(MIPS::Debugger &dbg) override;
};


#endif