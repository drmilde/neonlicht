#include "Port.h"

// static members
IDGenerator Port::IDG;

// constructors
Port::Port() {
}

Port::Port(std::string name, PortType t) {
  NAME = name;
  ID = NAME + IDG.nextID();
  type = t;
  value = 0.0;
}


// functions
std::string Port::getName() {
  return NAME;
}

std::string Port::getID() {
  return ID;
}

PortType Port::getType() {
  return type;
}

float Port::getValue() {
  return value;
}

void Port::setValue(float v) {
  value = v;
}
