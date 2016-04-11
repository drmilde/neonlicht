#ifndef _NOISE_GEN_h_
#define _NOISE_GEN_h_


#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  class NoiseGen: public UGen {

  public:
    NoiseGen();
    NoiseGen(std::string name);
    
    void control(std::string portName, float value);
    float tick(); // override standard implementation
    long count = 0;
    
  private:
    Port outPort;
    
  };
}

#endif
