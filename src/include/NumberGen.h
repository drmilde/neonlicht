#ifndef _NUMBER_GEN_h_
#define _NUMBER_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  class NumberGen: public UGen {

  public:
    NumberGen();
    NumberGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // overrides standard implementation

    // fast access function
    void setValue(float value);

  private:
    std::string name;
  
  };
}

#endif