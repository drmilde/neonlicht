#include "MultiSwitch5Gen.h"

using namespace unit;

MultiSwitch5Gen::MultiSwitch5Gen() : MultiSwitch5Gen("Amanda Brooks") {
}

MultiSwitch5Gen::MultiSwitch5Gen(std::string name) : UGen(name, 1) {
}

void MultiSwitch5Gen::control(std::string portName, float value) {
  if (portName == "select") { // select value
    setSelect(value);
  }
}


// fast access routines
void MultiSwitch5Gen::setSelect(float value) {
  select = ((int)value % 5); // restrict select values to [0,1,2,3,4]
}

float MultiSwitch5Gen::getIn4() {
  return in4;
}

float MultiSwitch5Gen::getIn5() {
  return in5;
}

// generate output

float MultiSwitch5Gen::tick() {
  // select in port
  
  setOut1(0.0); // default is silence

  switch (select) {
  case 0: {
    setOut1(getIn1());
    break;
  }
  case 1: {
    setOut1(getIn2());
    break;
  }
  case 2: {
    setOut1(getIn3());
    break;
  }
  case 3: {
    setOut1(getIn4());
    break;
  }
  case 4: {
    setOut1(getIn5());
    break;
  }
  }

  return (getOut1());
}
