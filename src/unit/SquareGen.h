#ifndef _SQUARE_GEN_h_
#define _SQUARE_GEN_h_


#include <stdlib.h>    
#include "OscillatorGen.h"

namespace unit {
  class SquareGen: public OscillatorGen {

  public:
    SquareGen();
    SquareGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation

  private:
    Port outPort;
  
    float frequency;

    float currentx;
    float currenty;
    float stepx;

  
  };
}

#endif
