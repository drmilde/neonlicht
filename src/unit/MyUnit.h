#ifndef _MY_UNIT_h_
#define _MY_UNIT_h_

#include "ArturiaMiniLabUnit.h"

class MyUnit : public ArturiaMiniLabUnit {
 public:
  MyUnit();
  float tick();

 private:
  void control(std::string portName, float value);

};


#endif
