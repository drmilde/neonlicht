#include "PulseGen.h"

using namespace unit;

PulseGen::PulseGen() : PulseGen("Everywhere I look something reminds me of her") {
  //do something useful here
}

PulseGen::PulseGen(std::string name) : CosineGen(name) {
  threshold1 = new ThresholdGen("threshold 1");
  control("pwm", 0.5);
}

void PulseGen::control(std::string portName, float value) {
  if (portName == "frequency") {
    setFrequency(value);
  }
  if (portName == "pwm") {
    threshold1->control("threshold", std::min(value, 0.99f));
  }
}

// fast access to input ports
void PulseGen::setPulseWidth(float value) {
  threshold1->setAmnt1(std::min(value, 0.99f));
}

void PulseGen::setFrequency(float value) {
  CosineGen::setFrequency(value);
}

float PulseGen::getFrequency() {
  CosineGen::getFrequency();
}


// create the sound

float PulseGen::tick() {
  // calculate the values
  // threshold the cosine, based on the given threshold level 

  threshold1->setIn1(CosineGen::tick());
  setOut1(threshold1->tick());

  // return current tick() value
  return getOut1();
}

