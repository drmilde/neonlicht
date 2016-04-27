#include "MyUnit.h"


MyUnit::MyUnit() : ArturiaMiniLabUnit("MyUnit") {
  // do something useful here
}


void MyUnit::control(std::string portName, float value) {
  std::cout << "In MyUnit : " << portName << ":" << value << std::endl;
}


float MyUnit::tick() {
  return 0.0;
}
