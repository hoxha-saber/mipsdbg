#ifndef PRINT_H
#define PRINT_H

#include "action.h"
class PrintAction : public Action {
    uint32_t reg;
    public:
    PrintAction(uint32_t x);
    void Execute(MIPS::Debugger &dbg) override;
};

#endif