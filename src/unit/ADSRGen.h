#ifndef _ADRS_GEN_h_
#define _ADRS_GEN_h_

#include <stdlib.h>
#include "EnvelopeGen.h"
#include "EGOneStepGen.h"
#include "GatedConstantGen.h"

namespace unit {
  class ADSRGen : public EnvelopeGen {

    enum States {ATTACK, DECAY, SUSTAIN, RELEASE, IDLE};

  public:
    ADSRGen();
    ADSRGen(std::string name);
    void control(std::string portName, float value);
    float tick();

    // fast access functuions
    void setTrigger();    
    void setGate(float value);


  private:
    void reset();

    States state;
    bool isTriggered;
    bool gate;

    float attack; // in seconds
    float decay; // in seconds
    float sustain; // value, usually in [0,1]
    float release; // in seconds
    float lastval;

    EGOneStepGen* AttackGen;
    EGOneStepGen* DecayGen;
    GatedConstantGen* SustainGen;
    EGOneStepGen* ReleaseGen;
  
  };
}


#endif
