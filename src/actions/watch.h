#ifndef WATCH_H
#define WATCH_H

#include "action.h"
class WatchAction : public Action {
    uint32_t addr;
    public:
    WatchAction(uint32_t x);
    void Execute(MIPS::Debugger &dbg) override;
};

class WatchRemoveAction : public Action {
    uint32_t addr;
    public:
    WatchRemoveAction(uint32_t x);
    void Execute(MIPS::Debugger &dbg) override;
};

#endif