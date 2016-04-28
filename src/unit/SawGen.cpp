#include "SawGen.h"

using namespace unit;

SawGen::SawGen() : SawGen("Comme ci, Comme ca") {
}

SawGen::SawGen(std::string name) : OscillatorGen(name) {
  // do something sensible here
  // add the ports
  outPort = Port("out", PortType::OUTPUT);
  addPort(outPort);

  setFrequency(440.0);

  stepy = (2.0 / SAMPLING_FREQUENCY);
  currentx = 0.0;
  currenty = -1.0;
}

// overrides control() in UGen
void SawGen::control(std::string portName, float value) {
  if (portName == "frequency") {
    setFrequency(value);
  }
}

// fast access to the input ports
void SawGen::setFrequency(float value) {
  frequency = fabs(value);
  stepx = (1 / SAMPLING_FREQUENCY) * frequency;
}

float SawGen::getFrequency() {
  return frequency;
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
