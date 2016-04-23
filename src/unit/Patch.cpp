#include "Patch.h"

Patch::Patch(std::string from, int ptFrom, std::string to, int pTo) {
  FROM = from;
  fromPort = ptFrom;
  TO = to;
  toPort = pTo;
}

std::string Patch::getFrom() {
  return FROM;
}

int Patch::getFromPort() {
  return fromPort;
}

std::string Patch::getTo() {
  return TO;
}

int Patch::getFormPort() {
  return toPort;
}

