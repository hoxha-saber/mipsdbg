#ifndef NEXT_H
#define NEXT_H
#include "action.h"
class NextAction : public Action {
    public:
    void Execute(MIPS::Debugger &dbg) override;
};


#endif