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
  /**
   * NumberGen stores a value.
   *
   * - **tick()** is providing the stored value.
   *
   * Control-Interface
   * -**control("non empty string", value)**: stores the value in amnt1. The portName has 
   * to be a non empty string, otherwise the value will not be stored.
   *
   * Fast access functions
   * - **setValue(float value)**: stores the value in amnt1 (and in out1).
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
