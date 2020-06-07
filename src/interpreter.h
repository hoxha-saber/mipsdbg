#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "ncurses.h"
#include <string>
#include <deque>
#include <iostream>
#include <memory>
#include "actions/action.h"
#include "scan.h"
enum Command {
    BreakpointSet = 0,
    BreakpointRemove,
    WatchSet,
    WatchRemove,
    Peek,
    Poke,
    Step,
    Run
};

class Interpreter {
    private:
    WINDOW *win;
    std::deque<std::string> buf;
    const std::string PROMPT = "(mipsdbg) ";
    const char BACKSPACE = 127;
    const char ENTER = 13;
    public:
    Interpreter();
    std::unique_ptr<Action> GetAction();
    ~Interpreter();
};

#endif