#ifndef _STK_ONE_POLE_GEN_h_
#define _STK_ONE_POLE_GEN_h_

#include "STKAdapterGen.h"
#include <iostream>    
#include <stdlib.h>
#include "Interpolation.h"

// include from STK
#include "OnePole.h"

namespace unit {
  /**
   * STKOnePoleGen is an adapter to the OnePole filter of the STK.
   * 
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
