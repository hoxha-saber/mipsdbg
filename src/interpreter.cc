#include "interpreter.h"

Interpreter::Interpreter() {
    win = newwin(LINES/3, COLS, (2*LINES)/ 3, 0);
}

Interpreter::~Interpreter() {
    delwin(win);
}

Command Interpreter::GetCommand() {

}