#ifndef _ADRS__NEW_GEN_h_
#define _ADRS__NEW_GEN_h_

#include <stdlib.h>
#include "EnvelopeGen.h"
#include "EGOneStepGen.h"
#include "GatedConstantGen.h"

namespace unit {
  class ADSR_NewGen : public EnvelopeGen {

    enum States {ATTACK, DECAY, SUSTAIN, RELEASE, IDLE, S_ATTACK, S_DECAY, S_SUSTAIN, S_RELEASE, RETRIGGER};

  public:
    ADSR_NewGen();
    ADSR_NewGen(std::string name);
    virtual ~ADSR_NewGen();

    void control(std::string portName, float value);
    float tick();

    // fast access functions
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

    float lastValue;

    EGOneStepGen* AttackGen;
    EGOneStepGen* DecayGen;
    GatedConstantGen* SustainGen;
    EGOneStepGen* ReleaseGen;
  
  };
}


#endif
