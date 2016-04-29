#ifndef _SQUARE_GEN_h_
#define _SQUARE_GEN_h_


#include <stdlib.h>    
#include "PulseGen.h"

namespace unit {
  class SquareGen: public PulseGen {

  public:
    SquareGen();
    SquareGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
    void setFrequency(float value);

  };
}

#endif
