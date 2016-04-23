#include "SoundUnit.h"

SoundUnit::SoundUnit():SoundUnit("RobertM") {
  // do something useful here
}

SoundUnit::SoundUnit(std::string name) {
  // do something useful here
  NAME = name;
}

void SoundUnit::addUGen(UGen* u) {
  // adding UGen to the SoundUnit
  UGENS[u->getName()] = u;
}

std::string SoundUnit::getName() {
  return NAME;
}


void SoundUnit::setup() {
  // implement the routing and routing sequence here
}

void SoundUnit::control(std::string portName, float value) {
  // implement the control here
}


float SoundUnit::tick() {
  // implement sound generation control for the unit here
  return 0;
}

