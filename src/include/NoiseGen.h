#ifndef _NOISE_GEN_h_
#define _NOISE_GEN_h_


#include <stdlib.h>    
#include "OscillatorGen.h"

namespace unit {
  class NoiseGen: public OscillatorGen {

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
