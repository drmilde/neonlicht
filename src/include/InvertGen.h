#ifndef _INVERT_GEN_h_
#define _INVERT_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {

/**
 * InvertGen is inverting the current in1.
 *
 * @author jtm
 * @since 04-2016
 * @version 1.0
 **/

  class InvertGen: public UGen {

  public:
    InvertGen();
    InvertGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
  
  };
}

#endif
