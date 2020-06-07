#include "interpreter.h"

Interpreter::Interpreter() {
    win = newwin(LINES/3, COLS, (2*LINES)/ 3, 0);
}

Interpreter::~Interpreter() {
    delwin(win);
}

std::unique_ptr<Action> Interpreter::GetAction() {
    buf.push_back(PROMPT);
    std::string cur;
    while(true) {
        for (int i = 0; i < std::min(LINES/3 - 1, static_cast<int>(buf.size())); ++i) {
            wmove(win, i, 0);
            wprintw(win, buf[i].c_str());
        }
        wrefresh(win);
        char c;
        std::cin >> std::noskipws;
        std::cin >> c;
        if (c == ENTER) {
            if (buf.size() >= static_cast<size_t>((LINES / 3) - 1)) {
                buf.pop_front();
                werase(win);
            }
            if (!cur.empty()){ 
                // build action
                return scan(cur);
                cur.clear();
            }
            buf.push_back(PROMPT);
        }
        else if (c == BACKSPACE) {
            if (!cur.empty()) {
                cur.pop_back();
                buf[buf.size() - 1].pop_back();
                werase(win);
            }
        }
        else {
            cur.push_back(c);
            buf[buf.size() - 1].push_back(c);
        }
    }
    return nullptr;
}