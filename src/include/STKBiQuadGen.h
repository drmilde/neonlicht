#ifndef _STK_BI_QUAD_GEN_h_
#define _STK_BI_QUAD_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "BiQuad.h"

namespace unit {
  /**
   * STKBiQuadGen is an adapter to the BiQuad filter of the STK.
   * 
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
