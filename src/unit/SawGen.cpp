#include "SawGen.h"

using namespace unit;

SawGen::SawGen() : SawGen("Comme ci, Comme ca") {
}

SawGen::SawGen(std::string name) : UGen(name, 1) {
  // do something sensible here
  // add the ports
  outPort = Port("out", PortType::OUTPUT);
  addPort(outPort);

  frequency = 440.0f;

  stepy = (2.0 / SAMPLING_FREQUENCY);
  stepx = (1 / SAMPLING_FREQUENCY) * frequency;
  currentx = 0.0;
  currenty = -1.0;
}


// overrides control() in UGen
void SawGen::control(std::string portName, float value) {
  if (portName == "frequency") {
    frequency = value;
    stepx = (1 / SAMPLING_FREQUENCY) * frequency;
  }
}


// overrides tick() in UGen
float SawGen::tick() {
  // calculate the values  
  //setPortValue("out", currenty);
  setOut1(currenty);
  
  currentx += stepx;  
  currenty += (frequency * stepy);
  
  if (currentx > 1.0) {
    currentx -= 1.0;
    currenty = -1.0;
  }
		      
  // return current tick() value
  // usually the value of the out port
  //return getPortValue("out");  
  return getOut1();
}
