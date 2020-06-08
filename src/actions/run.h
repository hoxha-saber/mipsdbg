#ifndef RUN_H
#define RUN_H
#include "action.h"
class RunAction : public Action {
    public:
    void Execute(MIPS::Debugger &dbg) override;
};

#endif