#include "IDGenerator.h"

int IDGenerator::CURRENT_ID;

IDGenerator::IDGenerator() {
  CURRENT_ID = 0;
}

std::string IDGenerator::nextID() {
  CURRENT_ID++;
  return ("--ID--" + std::to_string(CURRENT_ID));
}
