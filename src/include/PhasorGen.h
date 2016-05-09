#ifndef _PHASOR_GEN_h_
#define _PHASOR_GEN_h_

#include "SawGen.h"

namespace unit {
  class PhasorGen : public SawGen {
    
  public:
    PhasorGen();
    PhasorGen(std::string name);
    float tick();
    
  };
}

#endif
