#include "breakpoint.h"

BreakpointAction::BreakpointAction(uint32_t x) : addr{x} {}

void BreakpointAction::Execute(MIPS::Debugger &dbg) {
    dbg.setBreakpoint(addr);
}

BreakpointRemoveAction::BreakpointRemoveAction(uint32_t x) : addr{x} {}

void BreakpointRemoveAction::Execute(MIPS::Debugger &dbg) {
    dbg.removeBreakpoint(addr);
}


