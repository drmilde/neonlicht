#include "NumberGen.h"

using namespace unit;

NumberGen::NumberGen() : NumberGen("Short Circuit") {
}

NumberGen::NumberGen(std::string name) : UGen(name, 3) {
  // do something useful here
}


// overrides control() in UGen
void NumberGen::control(std::string portName, float value) {
  // stores value in amnt1
  if (portName != "") {
    UGen::setName(portName);
    setValue(value);
  }
}

void NumberGen::setValue(float value) {
  setAmnt1(value);
  setOut1(getAmnt1());
}


// overrides tick() in UGen
float NumberGen::tick() {
  // returns the value of amnt1
  		      
  // return current tick() value
  return getAmnt1();
}
