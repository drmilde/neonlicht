#ifndef _PULSE_GEN_h_
#define _PULSE_GEN_h_

#include "CosineGen.h"
#include "ThresholdGen.h"
#include <algorithm> 

namespace unit {
  class PulseGen : public CosineGen {
    
  public:
    PulseGen();
    PulseGen(std::string name);
    float tick();
    void control(std::string portName, float value);
    void setFrequency(float value);
    float getFrequency();
    void setPulseWidth(float value);


  private:
    unit::ThresholdGen* threshold1;

  };
}

#endif
