#include "SquareGen.h"

using namespace unit;

SquareGen::SquareGen() : SquareGen("Mr. White") {
}

SquareGen::SquareGen(std::string name) : OscillatorGen(name) {
  // do something sensible here
  // add the ports
  outPort = Port("out", PortType::OUTPUT);
  addPort(outPort);

  frequency = 440.0f;
  stepx = frequency * (1 / SAMPLING_FREQUENCY);
  currentx = 0;
  currenty = 0;
}


// overrides control() in UGen
void SquareGen::control(std::string portName, float value) {
  if (portName == "frequency") {
    frequency = value;
    stepx = frequency * (1 / SAMPLING_FREQUENCY);
  }
}

// overrides tick() in UGen
float SquareGen::tick() {
  // calculate the values
  //setPortValue("out", currenty);
  setOut1(currenty);


  currentx += stepx;
  if (currentx > 0.5) {
    currenty = 1.0;
  }
  
  if (currentx > 1.0) {
    currentx -= 1.0;
    currenty = 0;
  }
  
  // return current tick() value
  // usually the value of the out port
  return getOut1();
}
