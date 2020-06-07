#ifndef INTERPRETER_H
#define INTERPRETER_H
#include "ncurses.h"
#include <string>
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
    public:
    Interpreter();
    Command GetCommand();
    void SetPrompt();
    void SetLine(std::string text);
    ~Interpreter();
};

#endif