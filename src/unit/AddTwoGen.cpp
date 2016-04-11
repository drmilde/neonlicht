#include "AddTwoGen.h"

using namespace unit;

AddTwoGen::AddTwoGen() : AddTwoGen("Mr. White") {
}

AddTwoGen::AddTwoGen(std::string name) : UGen(name, 3) {
  // do something useful here
}


// overrides control() in UGen
void AddTwoGen::control(std::string portName, float value) {
  // no control interface
}


// overrides tick() in UGen
float AddTwoGen::tick() {
  // calculate the arithmetic mean of the two input values
  
  setOut1( (getIn1() + getIn2()) / 2.0) ;
		      
  // return current tick() value
  // usually the value of the out port
  //return getPortValue("out");  
  return getOut1();
}
