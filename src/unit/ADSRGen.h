#ifndef _ADRS_GEN_h_
#define _ADRS_GEN_h_

#include <stdlib.h>
#include "UGen.h"
#include "EGOneStepGen.h"
#include "GatedConstantGen.h"

namespace unit {
  class ADSRGen : public UGen {

    enum States {ATTACK, DECAY, SUSTAIN, RELEASE, IDLE};

  public:
    ADSRGen();
    ADSRGen(std::string name);
    void control(std::string portName, float value);

    float tick();

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
