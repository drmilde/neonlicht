#ifndef _PHASOR_GEN_h_
#define _PHASOR_GEN_h_

#include "SawGen.h"

namespace unit {
  /**
   * PhasorGen generates a standard ramp [0,1].
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class PhasorGen : public SawGen {
    
  public:
    PhasorGen();
    PhasorGen(std::string name);
    float tick();
    
  };
}

#endif
