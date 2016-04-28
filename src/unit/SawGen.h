#ifndef _SAW_GEN_h_
#define _SAW_GEN_h_

#include <stdlib.h>    
#include <math.h>
#include "UGen.h"

namespace unit {
  class SawGen: public UGen {
    
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
