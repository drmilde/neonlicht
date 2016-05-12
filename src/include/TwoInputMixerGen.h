#ifndef _TWO_INPUT_MIXER_GEN_h_
#define _TWO_INPUT_MIXER_GEN_h_


#include <iostream>    
#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  /**
   * TwoInputMixerGen is mixing the in ports **in1** and **in2**. Both values are
   * scaled by **amnt1** and **amnt2**. 
   * The mixer is calculating z = (in1 * amnt1) + (in2 * amnt2).
   * The in ports amnt1 and amnt1 are scaled by **0.5f** when being set with the control
   * interface.
   *
   * - **tick()** is providing the mixed value.
   *
   * Control-Interface
   *
   * - **control("amnt1", value)**: stores the value in amnt1. 
   * - **control("amnt2", value)**: stores the value in amnt2. 
   *
   * Fast access functions
   * - none, but the standard fast access functions
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class TwoInputMixerGen: public UGen {

  public:
    TwoInputMixerGen();
    TwoInputMixerGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);

  
  };
}

#endif
