#ifndef _SAW_GEN_h_
#define _SAW_GEN_h_

#include <stdlib.h>    
#include <math.h>
#include "OscillatorGen.h"

namespace unit {
  /**
   * SawGen generates a saw wave based on a simple linear interpolation.
   *
   * The implementation is not very effective and needs to be
   * redone. It also contains an implementation error.
   * It should use a wave table.
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class SawGen: public OscillatorGen {
    
  public:
    SawGen();
    SawGen(std::string name);
    
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
    void setFrequency(float value); // set the frequency
    float getFrequency(); // get the frequency

  private:
    Port outPort;
    float stepy;
    float stepx;
    float currentx;
    float currenty;
    
    float frequency;
    
  };
}

#endif
