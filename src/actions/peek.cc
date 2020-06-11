#include "peek.h"

PeekAction::PeekAction(uint32_t x, bool isReg) : addr{x} {}

void PeekAction::Execute(MIPS::Debugger &dbg) {
    // figure this out
    // is_reg ? : a : b;
}