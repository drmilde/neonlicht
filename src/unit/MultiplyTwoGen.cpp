#include "MultiplyTwoGen.h"

using namespace unit;

MultiplyTwoGen::MultiplyTwoGen() : MultiplyTwoGen("Made in Germany") {
}

MultiplyTwoGen::MultiplyTwoGen(std::string name) : UGen(name, 3) {
  // do something useful here
}


// overrides control() in UGen
void MultiplyTwoGen::control(std::string portName, float value) {
  // no control interface
}


// overrides tick() in UGen
float MultiplyTwoGen::tick() {
  // calculate the product of the two input values
  
  setOut1(getIn1() * getIn2());
		      
  // return current tick() value
  return getOut1();
}
