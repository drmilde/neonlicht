#ifndef _MULTIPLY_TWO_GEN_h_
#define _MULTIPLY_TWO_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  /**
   * MultiplyTwoGen multiplies the two standard input ports in1 and in2.
   *
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class MultiplyTwoGen: public UGen {

  public:
    MultiplyTwoGen();
    MultiplyTwoGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
  
  };
}

#endif
