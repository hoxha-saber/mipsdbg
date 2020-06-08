#include "watch.h"

WatchAction::WatchAction(uint32_t x) : addr{x} {

}

WatchAction::Execute(MIPS::Debugger &dbg) {
    dbg.setWatch(addr);
}
