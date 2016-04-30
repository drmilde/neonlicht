#include "ADSRGen.h"

using namespace unit;

ADSRGen::ADSRGen() : ADSRGen("") {
}

ADSRGen::ADSRGen(std::string name) : EnvelopeGen(name) {

  attack = 0.1;
  decay = 0.3;
  sustain = 0.5;
  release = 0.5;
  lastval = 0.0;
  
  AttackGen = new EGOneStepGen("Attack");
  AttackGen->setDuration(attack);
  AttackGen->setStartLevel(0.0);
  AttackGen->setEndLevel(1.0);

  DecayGen = new EGOneStepGen("Decay");
  DecayGen->setDuration(decay);
  DecayGen->setStartLevel(1.0);
  DecayGen->setEndLevel(sustain);

  SustainGen = new GatedConstantGen();
  SustainGen->control("value", sustain);
  SustainGen->control("gate", 1.0); // send value


  ReleaseGen = new EGOneStepGen("Release");
  ReleaseGen->setDuration(release);
  ReleaseGen->setStartLevel(sustain);
  ReleaseGen->setEndLevel(0.0);

  
  reset();
}

void ADSRGen::control(std::string portName, float value) {
  if (portName == "trigger") {
    setTrigger();
  }

  if (portName == "gate") {
    setGate(value);
  }
}

// fast access functions
void ADSRGen::setTrigger() {
  reset();
  isTriggered = true;
}

void ADSRGen::setGate(float value) {
  gate = (value >= 1);
}


void ADSRGen::reset() {
  state = IDLE;
  isTriggered = false;
  gate = false;

  AttackGen->reset(); // AN DIESER STELLE MUSS DER LASTVAL REIN, UM DEN OFFSET ZU SETZEN !!!!!!!
  DecayGen->reset();
  ReleaseGen->reset();
}

// berechne den aktuellen sample wert

float ADSRGen::tick() {
  // step through the states of the ADSR

  if ( (state == ATTACK) || (state == DECAY) || (state == SUSTAIN) ) { // ADSR is running
    if (!gate) { // key has been released
      state = RELEASE;
      ReleaseGen->setTrigger(); // trigger the ReleaseGen
    }
  }
  
  switch (state) {
  case IDLE: { // waiting for trigger
    setOut1(lastval);
    
    if (isTriggered) { // ADSR trigger is set, switch to ATTACK
      isTriggered = false; // process trigger impulse
      AttackGen->setTrigger(); // trigger the AttackGen
      
      state = ATTACK;
    }
    break;
  }
  case ATTACK: {      
    // process attack interpolation
    setOut1(AttackGen->tick());
    if (AttackGen->finished()) { // ready with attack phase? then switch to DECAY;
      state = DECAY;
      DecayGen->setTrigger(); // trigger the DecayGen
    }
    break;
  }
  case DECAY: {      
    // process decay interpolation
    setOut1(DecayGen->tick());
    if (DecayGen->finished()) { // ready with attack phase? then switch to SUSTAIN;
      state = SUSTAIN;
      SustainGen->control("amnt2", 1.0); // send sustain value      
    }
    break;
  }
  case SUSTAIN: {
    // process sustain hold
    setOut1(SustainGen->tick()); // send out value, as long as ADSR gate is 1 (key is pressed
    break;
  }
  case RELEASE: {
    // process release interpolation
    setOut1(ReleaseGen->tick()); // send out values, as long as key is pressed
    if (ReleaseGen->finished()) {
      reset(); // ready for next ADSR cycle
    }
    
    if (isTriggered) { // (another) key has been pressed
      // do something here, I dont really know what exactly :)
    }
    
    break;
  }
  }

  lastval =  getOut1(); // avoid zero drop, when playing fast notes
  
  return lastval;
}
