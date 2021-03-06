#ifndef ACTION_H
#define ACTION_H
#include "../dbg/debug.h"

class Action {
    public:
    virtual void Execute(MIPS::Debugger &dbg) = 0;
    virtual ~Action();
};

#endif