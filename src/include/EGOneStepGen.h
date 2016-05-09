#ifndef _EG_ONE_STEP_GEN_h_
#define _EG_ONE_STEP_GEN_h_

#include <iostream>    
#include <stdlib.h>    
#include "EnvelopeGen.h"
#include "Interpolation.h"

namespace unit {
  class EGOneStepGen: public EnvelopeGen {

  public:
    EGOneStepGen();
    EGOneStepGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);
    bool finished();

    // fast access function
    void setTrigger();
    void setDuration (float seconds);
    void setStartLevel (float level);
    void setEndLevel (float level);
    void reset();

  private:

    float startLevel; // start level of ramp, should be in [-1,1]
    float endLevel; // end level of ramp, should be in [-1,1]
    float duration; // duration in seconds

    int samples; // number of samples for the given duration
    int currentx; // the count of the current sample
    bool isReady; // is set to true, if process has run once completly
    bool hasStarted; // triggers the interpolation process
  
  };
}

#endif
