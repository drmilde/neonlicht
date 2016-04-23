#include "NumberGen.h"

NumberGen::NumberGen() : NumberGen("Mr. White") {
}

NumberGen::NumberGen(std::string name) : UGen(name, 3) {
  // do something useful here
}


// overrides control() in UGen
void NumberGen::control(std::string portName, float value) {
  // stores value in amnt1
  if (portName == "amnt1") {
    setAmnt1(value);
  }

}


// overrides tick() in UGen
float NumberGen::tick() {
  // calculate the arithmetic mean of the two input values
  
  setOut1(getAmnt1());
		      
  // return current tick() value
  return getOut1();
}
