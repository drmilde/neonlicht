#include "UGen.h"

// static members
IDGenerator UGen::IDG;

UGen::UGen():UGen("MAXM", 0) {
  // call the more specific constructor
}

UGen::UGen(std::string name, int pn) {
  NAME = name;
  ID = NAME + IDG.nextID();
  numberPorts = pn;
  ports = new Port[numberPorts];
  currentPort = 0;
}


// Port functions
void UGen::addPort(Port p) {
  if (getPortIndex(p.getName()) < 0) { // cannot add a port with same id twice
    if (currentPort < numberPorts) {
      ports[currentPort] = p;
      currentPort++;
    }
  } else {
    // error handling ... cannot add port with same name twice
  }
}

Port* UGen::getPorts() {
  return ports;
}

int UGen::getNumberOfPorts() {
  return currentPort; // retun the number of set ports in this ugen
}

float UGen::getPortValue(int pn) {
  if ((pn >= 0) && (pn < currentPort)) {
    return ports[pn].getValue();
  }
  return 0.0f;
}

float UGen::getPortValue(std::string name) {
  for (int idx = 0; idx < currentPort; idx++) {
    if (ports[idx].getName() == name) {
      return ports[idx].getValue();
    }
  }
  return 0.0f;
}

void UGen::setPortValue(int pn, float value) {
  if ((pn >= 0) && (pn < currentPort)) {
    ports[pn].setValue(value);
  }
}

void UGen::setPortValue(std::string name, float value) {
  for (int idx = 0; idx < currentPort; idx++) {
    if (ports[idx].getName() == name) {
      ports[idx].setValue(value);
    }
  }  
}

int UGen::getPortIndex(std::string name) {
  for (int idx = 0; idx < currentPort; idx++) {
    if (ports[idx].getName() == name) {
      return idx;
    }
  }
  return -1;
}

// default implementation ports control

void UGen::control (std::string portName, float value) {
  if (portName == "amnt1") {    
    setAmnt1(value);
  }
  if (portName == "amnt2") {
    setAmnt2(value);
  }
  if (portName == "amnt3") {
    setAmnt3(value);
  }
  if (portName == "in1") {
    setIn1(value);
  }
  if (portName == "in2") {
    setIn2(value);
  }
  if (portName == "out1") {
    setOut1(value);
  }
  if (portName == "out2") {
    setOut2(value);
  }
}

// default ports value getter/setter

void UGen::setAmnt1(float value) {
  amnt1 = value;
}

float UGen::getAmnt1() {
  return amnt1;
}

void UGen::setAmnt2(float value) {
  amnt2 = value;
}

float UGen::getAmnt2() {
  return amnt2;
}

void UGen::setAmnt3(float value) {
  amnt3 = value;
}

float UGen::getAmnt3() {
  return amnt3;
}

void UGen::setIn1(float value) {
  in1 = value;
}

float UGen::getIn1() {
  return in1;
}

void UGen::setIn2(float value) {
  in2 = value;
}

float UGen::getIn2() {
  return in2;
}

void UGen::setOut1(float value) {
  out1 = value;
}

float UGen::getOut1() {
  return out1;
}

void UGen::setOut2(float value) {
  out2 = value;
}

float UGen::getOut2() {
  return out2;
}

// end of default ports


// Name and ID

std::string UGen::getName() {
  return NAME;
}

std::string UGen::getID() {
  return ID;
}

// Data processing
// default implementation is giving you silence
float UGen::tick() {
  return 0.0; // silence is golden
}

