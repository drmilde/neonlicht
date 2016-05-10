#ifndef _STK_ONE_ZERO_GEN_h_
#define _STK_ONE_ZERO_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "OneZero.h"

namespace unit {
  /**
   * STKOneZeroGen is an adapter to the OneZero filter of the STK.
   * 
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class STKOneZeroGen : public STKAdapterGen {

  public:
    STKOneZeroGen();
    void control (std::string portName, float value);
    float tick();

  private:
    stk::OneZero stkOneZero;
  
  };
}

#endif
