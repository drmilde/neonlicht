#ifndef _STK_TWO_POLE_GEN_h_
#define _STK_TWO_POLE_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "TwoPole.h"

namespace unit {
  class STKTwoPoleGen : public STKAdapterGen {

  public:
    STKTwoPoleGen();
    void control (std::string portName, float value);
    float tick();

  private:
    void updateSettings();
    float frequency;
    float radius;
    stk::TwoPole stkTwoPole;
  
  };
}

#endif
