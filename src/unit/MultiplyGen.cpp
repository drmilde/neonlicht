#include "MultiplyGen.h"

using namespace unit;

MultiplyGen::MultiplyGen() : MultiplyGen("Larger than life") {
}

MultiplyGen::MultiplyGen(std::string name) : UGen(name, 3) {
  // do something useful here
}


// overrides control() in UGen
void MultiplyGen::control(std::string portName, float value) {
  // no control interface
}


// overrides tick() in UGen
float MultiplyGen::tick() {
  // calculate the product of amnt1 and in1 
  
  setOut1(getIn1() * getAmnt1());
		      
  // return current tick() value
  return getOut1();
}
