#ifndef _STK_ONE_POLE_GEN_h_
#define _STK_ONE_POLE_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "util/Interpolation.h"

// include from STK
#include "OnePole.h"

namespace unit {
  class STKOnePoleGen : public STKAdapterGen {

  public:
    STKOnePoleGen();
    void control (std::string portName, float value);
    float tick();

  private:
    stk::OnePole stkOnePole;
  
  };
}

#endif
