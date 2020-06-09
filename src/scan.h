#ifndef SCAN_H 
#define SCAN_H
#include <memory>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "actions/actions.h"
#include <vector>

const char* BREAKPOINTADD_T = "+bp";
const char* BREAKPOINTREM_T = "-bp";
const char* WATCHADD_T = "+watch";
const char* WATCHREM_T = "-watch";
const char* PEEK_T = "peek";
const char* POKE_T = "poke";
const char* NEXT_T = "next";
const char* RUN_T = "run";
const char* DOLLAR = "$";

std::unique_ptr<Action> scan(std::string &line);

#endif