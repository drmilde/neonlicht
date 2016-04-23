#include "STKTwoPoleGen.h"

STKTwoPoleGen::STKTwoPoleGen() {
  // do something useful here
  stkTwoPole = stk::TwoPole();
  frequency = 440.0;
  radius = 0.5;
}

void STKTwoPoleGen::control (std::string portName, float value) {
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
}

void STKTwoPoleGen::updateSettings() {
  stkTwoPole.setResonance(frequency, radius, true); // do not normalize
}

float STKTwoPoleGen::tick() {
  setOut1(stkTwoPole.tick(getIn1()));
  return getOut1();
}
