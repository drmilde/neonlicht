#include "OnePoleLPFGen.h"


OnePoleLPFGen::OnePoleLPFGen() : OnePoleLPFGen("Lili Marleen") {
}

OnePoleLPFGen::OnePoleLPFGen(std::string name) : UGen(name, 4) {
  // add the ports
  cutoffPort = Port("cutoff", PortType::VALUE);  
  lastPort = Port("last", PortType::VALUE);  
  inPort = Port("in1", PortType::INPUT);
  outPort = Port("out", PortType::OUTPUT);
  
  addPort(inPort);
  addPort(outPort);
  addPort(lastPort);
  addPort(cutoffPort);

  //setPortValue("last", 0.0f);
  setAmnt1(0.0); // amnt1 = last
  
  //setPortValue("cutoff", 0.5f);
  setAmnt2(0.5); // amnt2 = cutoff

  cutoff = getAmnt2(); // amnt2 = cuttoff
}

void OnePoleLPFGen::control(std::string portName, float value) {

  if (portName == "cutoff") {
    //setPortValue(portName, value);
    setAmnt2(value); // amnt2 = cutoff
    cutoff = getAmnt2(); // amnt2 = cutoff
  }
}


// overrides tick() in UGen
float OnePoleLPFGen::tick() {
  // calculate the values
  // a = 0.99f
  // z = (in * (1.0 - a)) + (z * a)
  
  float z = (getIn1() * (1.0f - cutoff)) +  (getAmnt1() * cutoff);
  
  //setPortValue("last", z);
  setAmnt1(z); // amnt1 = last = z  
  //setPortValue("out", z);
  setOut1(z);

  
  // return current tick() value
  // usually the value of the out port
  return getOut1();
}

