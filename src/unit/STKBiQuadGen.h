#ifndef _STK_BI_QUAD_GEN_h_
#define _STK_BI_QUAD_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "BiQuad.h"

namespace unit {
  class STKBiQuadGen : public STKAdapterGen {

  public:
    STKBiQuadGen();
    void control (std::string portName, float value);
    float tick();

  private:
    void updateSettings();
    float frequency;
    float radius;
    float type;
    stk::BiQuad stkBiQuad;
  
  };
}

#endif
