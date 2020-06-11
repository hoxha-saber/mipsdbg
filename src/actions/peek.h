#ifndef PEEK_H
#define PEEK_H
#include "action.h"
class PeekAction : public Action {
    uint32_t addr;
    bool is_reg;
    public:
    PeekAction(uint32_t x, bool isReg);
    void Execute(MIPS::Debugger &dbg) override;
};


#endif