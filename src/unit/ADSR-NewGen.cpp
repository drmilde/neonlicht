#include "ADSR-NewGen.h"

using namespace unit;

ADSR_NewGen::ADSR_NewGen() : ADSR_NewGen("") {
}

ADSR_NewGen::ADSR_NewGen(std::string name) : EnvelopeGen(name) {
  
  AttackGen = new EGOneStepGen("attack");
  DecayGen = new EGOneStepGen("decay");
  SustainGen = new GatedConstantGen("sustain");
  ReleaseGen = new EGOneStepGen("release");

  AttackGen->setDuration(1.0);
  AttackGen->setStartLevel(0.0);
  AttackGen->setEndLevel(1.0);

  DecayGen->setDuration(1.0);
  DecayGen->setStartLevel(1.0);
  DecayGen->setEndLevel(0.5);

  SustainGen->setLevel(0.5);
  SustainGen->setGate(0.0);

  ReleaseGen->setDuration(1.0);
  ReleaseGen->setStartLevel(0.5);
  ReleaseGen->setEndLevel(0.0);

  reset();

}

void ADSR_NewGen::control(std::string portName, float value) {
}

// fast access functions
void ADSR_NewGen::setTrigger() {
  isTriggered = true;
}

void ADSR_NewGen::setGate(float value) {
  gate = (value >= 1);
}

void ADSR_NewGen::setAttack(float value) {
}

void ADSR_NewGen::setDecay(float value) {
}

void ADSR_NewGen::setSustain(float value) {
}

void ADSR_NewGen::setRelease(float value) {
}

void ADSR_NewGen::reset() {
  AttackGen->reset();
  DecayGen->reset();
  // Sustain runs forever
  ReleaseGen->reset();

  state = IDLE;
  // no trigger, no gate
  isTriggered = false;
  setGate(0);
}

// berechne den aktuellen sample wert

float ADSR_NewGen::tick() {
  // step through the states of the ADSR
  setOut1(0.0); // be silent, if not running
  
  switch(state) {

  case IDLE: {
    if (isTriggered) {
      isTriggered = false; // consume trigger
      state = S_ATTACK; // ATTACK START
    }
    if ((!gate) && (!isTriggered)) {
      state = IDLE;
    }
    break;
  }
   
  case ATTACK: {
    if (!gate) {
      state = S_RELEASE; //RELEASE START
    }
    if (gate) {      
      state = ATTACK;
    }
    if ((gate) && (AttackGen->finished())) {
      state = S_DECAY; // DECAY START
    }
    setOut1(AttackGen->tick());
    break;
  }
    
  case DECAY: {
    if (!gate) {
      state = S_RELEASE; // RELEASE START
    }
    if (gate) {
      state = DECAY;
    }
    if ((gate) && (DecayGen->finished())) {
      state = S_SUSTAIN; //SUSTAIN START
    }
    setOut1(DecayGen->tick());
    break;
  }
    
  case SUSTAIN: {
    if (!gate) {
      state = S_RELEASE; // RELEASE START
    }
    if (gate) {
      state = SUSTAIN;
    }
    setOut1(SustainGen->tick());
    break;
  }
    
  case RELEASE: {
    // what to do ?
    if (isTriggered) { // pressed a new key in release phase -> retigger
      state = RETRIGGER;
    }
    if (ReleaseGen->finished()) { // everthing is finshed, reset adsr
      reset();
      state = IDLE;
    }
    setOut1(ReleaseGen->tick());
    break;
  }

    // the start states
  case S_ATTACK : {
    AttackGen->setTrigger();
    state = ATTACK;
    break;
  }
  case S_DECAY: {
    DecayGen->setTrigger();
    state = DECAY;
    break;
  }
  case S_SUSTAIN: {
    SustainGen->setGate(1);
    state = SUSTAIN;
    break;
  }
  case S_RELEASE: {
    ReleaseGen->setTrigger();
    state = RELEASE;
    break;
  }
  case RETRIGGER: {
    // do something .. but what
    state = IDLE;
    break;
  }
    
  }
  
  lastValue = getOut1();
  return lastValue;
}
