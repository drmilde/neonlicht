#include "TwoInputMixerGen.h"

using namespace unit;

TwoInputMixerGen::TwoInputMixerGen() : TwoInputMixerGen("Tom Cruise") {
}

TwoInputMixerGen::TwoInputMixerGen(std::string name) : UGen(name, 5) {
  // add the ports
  amntPort1 = Port("amnt1", PortType::VALUE);  
  amntPort2 = Port("amnt2", PortType::VALUE);  
  inPort1 = Port("in1", PortType::INPUT);
  inPort2 = Port("in2", PortType::INPUT);
  outPort = Port("out", PortType::OUTPUT);

  addPort(amntPort1);
  addPort(amntPort2);
  addPort(inPort1);
  addPort(inPort2);
  addPort(outPort);


  //setPortValue("in1", 0.0f);
  //setPortValue("in2", 0.0f);
  //setPortValue("amnt1", 0.0f);
  //setPortValue("amnt2", 0.0f);

  setIn1(0.0f);
  setIn2(0.0f);
  setAmnt1(0.0f);
  setAmnt2(0.0f);

  amnt1 = getAmnt1() * 0.5f;
  amnt2 = getAmnt2() * 0.5f;

  std::cout << "amnt1 = " << amnt1 << std::endl;
}

void TwoInputMixerGen::control (std::string portName, float value) {
  if (portName == "amnt1") {    
    setAmnt1(value * 0.5f);
  }
  if (portName == "amnt2") {
    setAmnt2(value * 0.5f);
  }
}


// overrides tick() in UGen
float TwoInputMixerGen::tick() {
  // calculate the values
  // z = ((amnt1 * in1) + (amnt2 * in2));


  setOut1((getAmnt1() * getIn1()) +
	  (getAmnt2() * getIn2()));

  // return current tick() value
  // usually the value of the out port
  return getOut1();
}

