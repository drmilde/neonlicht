#include "ThresholdGen.h"

using namespace unit;

ThresholdGen::ThresholdGen() : ThresholdGen("The final frontier") {
}

ThresholdGen::ThresholdGen(std::string name) : UGen(name, 0) {
  // do something useful here
}


// overrides control() in UGen
void ThresholdGen::control(std::string portName, float value) {
  if (portName == "threshold") {
    setAmnt1(fabs(value));
  }
}


// overrides tick() in UGen
float ThresholdGen::tick() {
  // if fabs(in1) > amnt1 => 1.0, else 0.0 
  
  setOut1( (getIn1() > getAmnt1()? 1.0: 0.0 ) ) ;
  setOut1( (getIn1() < -getAmnt1()? -1.0: 0.0 ) ) ;
		      
  // return current tick() value
  return getOut1();
}
