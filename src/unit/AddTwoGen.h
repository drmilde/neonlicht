#ifndef _ADD_TWO_GEN_h_
#define _ADD_TWO_GEN_h_


#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  class AddTwoGen: public UGen {

  public:
    AddTwoGen();
    AddTwoGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
  
  };
}

#endif
