#ifndef SCAN_H 
#define SCAN_H
#include <memory>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "actions/actions.h"
#include <vector>

const char* BREAKPOINT_T = "bp";
const char* WATCH_T = "watch";
const char* PEEK_T = "peek";
const char* POKE_T = "poke";
const char* NEXT_T = "next";
const char* RUN_T = "run";

std::unique_ptr<Action> scan(std::string &line);

#endif