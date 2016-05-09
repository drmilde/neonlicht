#ifndef _STK_TWO_ZERO_GEN_h_
#define _STK_TWO_ZERO_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "TwoZero.h"

namespace unit {
  class STKTwoZeroGen : public STKAdapterGen {

  public:
    STKTwoZeroGen();
    void control (std::string portName, float value);
    float tick();

  private:
    void updateSettings();
    float frequency;
    float radius;
    stk::TwoZero stkTwoZero;
  
  };
}

#endif
