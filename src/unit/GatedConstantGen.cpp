#include "GatedConstantGen.h"

using namespace unit;

GatedConstantGen::GatedConstantGen() : GatedConstantGen("Frank Morris") {
}

GatedConstantGen::GatedConstantGen(std::string name) : UGen(name, 1) {
  isGated = true;
  setAmnt1(0.0); // init amnt1 to silence
}

void GatedConstantGen::control(std::string portName, float value) {
  if (portName == "value") { // value to be sent
    setLevel(value);
  }
  
  if (portName == "gate") {// gate value, if value >= 1, value will be sent, else 0.0;
    setGate(value);
  }
}

// fast access fuctions
void GatedConstantGen::setLevel(float value) {
  setAmnt1(value);
}

void GatedConstantGen::setGate(float value) {
    setAmnt2(value);
    isGated = (getAmnt2() < 1);
}


float GatedConstantGen::tick() {
  // if gated, result is 0, else amnt1
  
  if (isGated) {
    return 0;
  } else {
    return (getAmnt1());
  }
  
}
