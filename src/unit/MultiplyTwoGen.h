#ifndef _MULTIPLY_TWO_GEN_h_
#define _MULTIPLY_TWO_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  class MultiplyTwoGen: public UGen {

  public:
    MultiplyTwoGen();
    MultiplyTwoGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
  
  };
}

#endif
