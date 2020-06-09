#include "watch.h"

WatchAction::WatchAction(uint32_t x) : addr{x} { }

void WatchAction::Execute(MIPS::Debugger &dbg) {
    dbg.setWatch(addr);
}

WatchRemoveAction::WatchRemoveAction(uint32_t x) : addr{x} {}

void WatchRemoveAction::Execute(MIPS::Debugger &dbg) {
    dbg.removeWatch(addr);
}