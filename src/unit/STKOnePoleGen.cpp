#include "STKOnePoleGen.h"

STKOnePoleGen::STKOnePoleGen() {
  // do something useful here
  stkOnePole = stk::OnePole(-1.0);
}

void STKOnePoleGen::control (std::string portName, float value) {
  if (portName == "amnt1") {    
    setAmnt1(Interpolation::map(value, 0.0, 1.0, -0.9999, 0.9999));
    std::cout << "pole value = " << getAmnt1() << std::endl;
    stkOnePole.setPole(getAmnt1());
  }
}

float STKOnePoleGen::tick() {
  setOut1(stkOnePole.tick(getIn1()));
  return getOut1();
}
