#include "scan.h"

std::unique_ptr<Action> scan(std::string &line) {
    std::istringstream iss {line};
    std::vector<std::string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
    if (tokens.size() == 2) {
        if (tokens[0] == BREAKPOINT_T) {
            
        }
        else if (tokens[0] == WATCH_T) {

        }
        else if (tokens[0] == PEEK_T) {

        }
        else if (tokens[0] == POKE_T) {

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