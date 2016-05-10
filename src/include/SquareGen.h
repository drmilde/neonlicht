#ifndef _SQUARE_GEN_h_
#define _SQUARE_GEN_h_


#include <stdlib.h>    
#include "PulseGen.h"

namespace unit {
  /**
   * SquareGen generates a square wave. It is derived from
   * PulseGen and sets the pulse width to 50%.
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
