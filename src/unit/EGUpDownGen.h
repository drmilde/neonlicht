#ifndef _EG_UP_DOWN_GEN_h_
#define _EG_UP_DOWN_GEN_h_


#include <stdlib.h>    
#include "UGen.h"
#include "util/Interpolation.h"

namespace unit {
  class EGUpDownGen: public UGen {

  public:
    EGUpDownGen();
    EGUpDownGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);

  private:
    void reset();
  
    Port durationPort;
    Port triggerPort;
    Port outPort;

    float duration; // in seconds
    int numberTicks;
    int currentTick;
    bool up;
  
  };
}

#endif
