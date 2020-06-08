#include "breakpoint.h"

BreakpointAction::BreakpointAction(uint32_t x) : addr{x} {}

BreakpointAction::Execute(MIPS::Debugger &dbg) {
    dbg.setBreakpoint(addr);
}

