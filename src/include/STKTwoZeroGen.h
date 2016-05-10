#ifndef _STK_TWO_ZERO_GEN_h_
#define _STK_TWO_ZERO_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "TwoZero.h"

namespace unit {
  /**
   * STKTwoZeroGen is an adapter to the Twozero filter of the STK.
   * 
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
