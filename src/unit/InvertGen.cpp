#include "InvertGen.h"

using namespace unit;

InvertGen::InvertGen() : InvertGen("") {
}

InvertGen::InvertGen(std::string name) : UGen(name, 3) {
  // do something useful here
}


// overrides control() in UGen
void InvertGen::control(std::string portName, float value) {
  // no control interface
}

// overrides tick() in UGen
float InvertGen::tick() {
  // calculates the inverse of in1
  
  setOut1( -getIn1() ) ;
		      
  // return current tick() value
  return getOut1();
}
