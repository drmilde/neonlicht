#include "STKBiQuadGen.h"

using namespace unit;

STKBiQuadGen::STKBiQuadGen() {
  // do something useful here
  stkBiQuad = stk::BiQuad();
  frequency = 440.0;
  radius = 0.5;
}

void STKBiQuadGen::control (std::string portName, float value) {
  if (portName == "amnt1") { // frequency between 0.0 and 1/2 of Sampling_Frequency
    frequency = Interpolation::map(value, 0.0, 1.0, 0.0, (SAMPLING_FREQUENCY / 4));
    //std::cout << "center frequency = " << frequency << std::endl;
    setAmnt1(frequency); // amnt1 = frequency;
    updateSettings();
  }
  if (portName == "amnt2") { // radius between 0.0 and 2.0, allowing to create stable filter
    radius = Interpolation::map(value, 0.0, 1.0, 0.7, 0.9999f);
    //std::cout << "radius = " << radius << std::endl;
    setAmnt2(radius); // amnt2 = radius;
    updateSettings();
  }
  if (portName == "amnt3") { // type := 0 => resonance, type := 1 => notch
    type = Interpolation::discrete(value, 0.0, 1.0, 1);
    //std::cout << "type = " << type << std::endl;
    setAmnt3(type); // amnt2 = type;
    updateSettings();
  }
}

void STKBiQuadGen::updateSettings() {
  if (type == 0) {
    stkBiQuad.setResonance(frequency, radius, true); // do normalize
  }
  if (type == 1) {
    stkBiQuad.setNotch(frequency, radius); // 
  }
}

float STKBiQuadGen::tick() {
  setOut1(stkBiQuad.tick(getIn1()));
  return getOut1();
}
