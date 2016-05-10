#ifndef _PULSE_GEN_h_
#define _PULSE_GEN_h_

#include "CosineGen.h"
#include "ThresholdGen.h"
#include <algorithm> 

namespace unit {
  /**
   * PulseGen generates a pulse wave form with variable pulse
   * width. It is derived from CosineGen and performs a 
   * threshold operation.
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
