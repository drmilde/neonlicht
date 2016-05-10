#ifndef _OSCILLATOR_GEN_h_
#define _OSCILLATOR_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

namespace unit {
  /**
   * OscillatorGen is an intermedediate class and serves as 
   * a general base class for all oscillators. 
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class OscillatorGen: public UGen {
    
  public:
    OscillatorGen();
    OscillatorGen(std::string name);
    
  };
}

#endif
