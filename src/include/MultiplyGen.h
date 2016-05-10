#ifndef _MULTIPLY_GEN_h_
#define _MULTIPLY_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  /**
   * MultiplyGen is a minimal mixing unit. 
   * It multiplies the **in1** port with **amnt1** port.
   *
   * - **tick()** is providing the product of **in1** and **amnt1**.
   *
   * Control-Interface
   * - no control interface implemented
   *
   * Fast access functions
   * - no further fast access functions implemented
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class MultiplyGen: public UGen {

  public:
    MultiplyGen();
    MultiplyGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
  
  };
}

#endif
