#include "STKOneZeroGen.h"

STKOneZeroGen::STKOneZeroGen() {
  // do something useful here
  stkOneZero = stk::OneZero(-1.0);
}

void STKOneZeroGen::control (std::string portName, float value) {
  if (portName == "amnt1") {    
    setAmnt1(Interpolation::map(value, 0.0, 1.0, -1.0, 1.0));
    stkOneZero.setZero(getAmnt1());
  }
}

float STKOneZeroGen::tick() {
  setOut1(stkOneZero.tick(getIn1()));
  return getOut1();
}
