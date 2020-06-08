#include "oops.h"

void MIPS::error(const std::string &msg) {
  throw msg;
}
