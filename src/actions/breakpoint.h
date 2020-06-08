#ifndef BREAKPOINT_H
#define BREAKPOINT_H
#include "action.h"
class BreakpointAction : public Action {
    uint32_t addr;
    public:
    BreakpointAction(uint32_t x);
    void Execute(MIPS::Debugger &dbg) override;
};

class BreakpointRemoveAction : public Action {
    uint32_t addr;
    public:
    BreakpointRemoveAction(uint32_t x);
    void Execute(MIPS::Debugger &dbg) override;
};


#endif