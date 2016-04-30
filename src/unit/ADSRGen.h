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

    void setAttack(float value);
    void setDecay(float value);
    void setSustain(float value);
    void setRelease(float value);


  private:
    void reset();

    States state;
    bool isTriggered;
    bool gate;

    float lastval;

    EGOneStepGen* AttackGen;
    EGOneStepGen* DecayGen;
    GatedConstantGen* SustainGen;
    EGOneStepGen* ReleaseGen;
  
  };
}


#endif
