#include "SquareGen.h"

using namespace unit;

SquareGen::SquareGen() : SquareGen("Hip to be Square") {
}

SquareGen::SquareGen(std::string name) : PulseGen(name) {
  // do something sensible here

  PulseGen::setPulseWidth(0.5);
  setFrequency(440.0);
}


// overrides control() in UGen
void SquareGen::control(std::string portName, float value) {
  if (portName == "frequency") {
    setFrequency(value);
  }
}

// fast access routines
void SquareGen::setFrequency(float value) {
    PulseGen::setFrequency(value);
}

// overrides tick() in UGen
float SquareGen::tick() {
  // calculate the values

  setOut1(PulseGen::tick());
  
  
  // return current tick() value
  // usually the value of the out port
  return getOut1();
}
