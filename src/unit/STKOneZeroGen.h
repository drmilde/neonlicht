#ifndef _STK_ONE_ZERO_GEN_h_
#define _STK_ONE_ZERO_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "OneZero.h"

class STKOneZeroGen : public STKAdapterGen {

 public:
  STKOneZeroGen();
  void control (std::string portName, float value);
  float tick();

 private:
  stk::OneZero stkOneZero;
  
};

#endif
