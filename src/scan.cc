#include "scan.h"
#include "actions/action.h"

std::unique_ptr<Action> scan(std::string &line) {
    std::istringstream iss {line};
    std::vector<std::string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
    if (tokens.size() == 3) {
        uint32_t arg1 = std::stoi(tokens[1]);
        uint32_t arg2 = std::stoi(tokens[2]);
        if (tokens[0] == POKE_T) {
            // determine if its address or register
            return std::make_unique<PokeAction>(arg1, arg2);
        }
    }

    else if (tokens.size() == 2) {
        uint32_t arg = std::stoi(tokens[1]);
        if (tokens[0] == BREAKPOINTADD_T) {
            return std::make_unique<BreakpointAction>(arg);
        }
        else if (tokens[0] == BREAKPOINTREM_T) {

        }
        else if (tokens[0] == WATCHADD_T) {
            // determine if its address or register
        }
        else if (tokens[0] == WATCHREM_T) {

        }
        else if (tokens[0] == PEEK_T) {

        }
        else {
            return nullptr;
        }
    }
    else if (tokens.size() == 1) {
        if (tokens[0] == NEXT_T) {

        }
        else if (tokens[0] == RUN_T) {

        }
        else {
            return nullptr;
        }
    }
    else {
        return nullptr;
    }
}