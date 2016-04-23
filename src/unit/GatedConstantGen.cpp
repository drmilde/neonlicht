#include "GatedConstantGen.h"

GatedConstantGen::GatedConstantGen() : GatedConstantGen("Frank Morris") {
}

GatedConstantGen::GatedConstantGen(std::string name) : UGen(name, 1) {
  isGated = true;
  setAmnt1(0.0); // init amnt1 to silence
}

void GatedConstantGen::control(std::string portName, float value) {
  if (portName == "amnt1") { // value to be sent
    setAmnt1(value);
  }
  
  if (portName == "amnt2") {// gate value, if value >= 1, value will be sent, else 0.0;
    setAmnt2(value);
    isGated = (getAmnt2() < 1);
  }
}

float GatedConstantGen::tick() {
  // if gated, result is 0, else amnt1
  
  if (isGated) {
    return 0;
  } else {
    return (getAmnt1());
  }
  
}
