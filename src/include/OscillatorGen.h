#ifndef _OSCILLATOR_GEN_h_
#define _OSCILLATOR_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  class OscillatorGen: public UGen {
    
  public:
    OscillatorGen();
    OscillatorGen(std::string name);
    
  };
}

#endif
