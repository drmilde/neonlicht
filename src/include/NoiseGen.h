#ifndef _NOISE_GEN_h_
#define _NOISE_GEN_h_


#include <stdlib.h>    
#include "OscillatorGen.h"

namespace unit {
  /**
   * NoiseGen generates white noise.
   *
   * - **tick()** is providing a random value in the range of [-1,1].
   *
   * Control-Interface
   * - no control interface implemented
   *
   * Fast access functions
   * - no further fast access functions implemented
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
