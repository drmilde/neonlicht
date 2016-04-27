#include "MyUnit.h"


MyUnit::MyUnit() : ArturiaMiniLabUnit("MyUnit") {
  // do something useful here
  cosine1 = new unit::CosineGen("osc 1");
  threshold1 = new unit::ThresholdGen("thresh 1");
  waveOut = new unit::WaveOutGen("wave 1");
}

void MyUnit::control(std::string portName, float value) {
  if (portName == "param 1") {
    cosine1->control("frequency", value*880.0);
  }
  if (portName == "param 2") {
    threshold1->control("threshold", value);
  }
  if (portName == "pad 15") {
    waveOut->control("record", 1);
  }
  if (portName == "pad 16") {
    waveOut->control("record", 0);
  }
}


float MyUnit::tick() {
  threshold1->setIn1(cosine1->tick());
  waveOut->setIn1(threshold1->tick());

  return waveOut->tick();
}
