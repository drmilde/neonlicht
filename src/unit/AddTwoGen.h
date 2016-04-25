#ifndef _ADD_TWO_GEN_h_
#define _ADD_TWO_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {

/**
 * AddTwoGen is calculating the arithmetic mean of Port in1 and Port in2.
 * It provides a very basic two input mixing unit, adding together the Ports 
 * in1 and in2.
 *
 * @author jtm
 * @since 04-2016
 * @version 1.0
 **/

  class AddTwoGen: public UGen {

  public:
    AddTwoGen();
    AddTwoGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
  
  };
}

#endif
