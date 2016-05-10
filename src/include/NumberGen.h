#ifndef _NUMBER_GEN_h_
#define _NUMBER_GEN_h_

#include <stdlib.h>    
#include "UGen.h"


/**
 * NumberGen is storing a single numerial value.
 *
 * @author jtm
 * @since 04-2016
 * @version 1.0
 **/

namespace unit {
  class NumberGen: public UGen {

  public:
    NumberGen();
    NumberGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // overrides standard implementation

    // fast access function
    void setValue(float value);
  };
}

#endif
