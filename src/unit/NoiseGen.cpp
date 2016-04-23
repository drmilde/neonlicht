#include "NoiseGen.h"


NoiseGen::NoiseGen() : NoiseGen("Mr. White") {
}

NoiseGen::NoiseGen(std::string name) : UGen(name, 1) {
  // do something sensible here
  // add the ports
  outPort = Port("out", PortType::OUTPUT);
  addPort(outPort);
}

void NoiseGen::control(std::string portName, float value) {
}


// overrides tick() in UGen
float NoiseGen::tick() {
  // calculate the values
  //setPortValue("out",(((rand() % 200) - 100) / 100.0));

  setOut1( (((rand() % 200) - 100) / 100.0) );
 
  // return current tick() value
  // usually the value of the out port
  //return getPortValue("out");
  return getOut1();
}


