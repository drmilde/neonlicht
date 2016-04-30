#include "ADSRGen.h"

using namespace unit;

ADSRGen::ADSRGen() : ADSRGen("") {
}

ADSRGen::ADSRGen(std::string name) : EnvelopeGen(name) {

  lastval = 0.0;
  
  AttackGen = new EGOneStepGen("Attack");
  DecayGen = new EGOneStepGen("Decay");  
  SustainGen = new GatedConstantGen();
  ReleaseGen = new EGOneStepGen("Release");

  setAttack(0.1);
  setDecay(0.3);
  setSustain(0.5);
  setRelease(0.5);
  
  reset();
}


void ADSRGen::control(std::string portName, float value) {
  if (portName == "trigger") {
    setTrigger();
  }

  if (portName == "gate") {
    setGate(value);
  }

  if (portName == "attack") {
    setAttack(value);
  }

  if (portName == "decay") {
    setDecay(value);
  }

  if (portName == "sustain") {
    setSustain(value);
  }

  if (portName == "release") {
    setRelease(value);
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

void ADSRGen::setAttack(float value) {
  AttackGen->setDuration(value);
  AttackGen->setStartLevel(0.0);
  AttackGen->setEndLevel(1.0);
}

void ADSRGen::setDecay(float value) {
  DecayGen->setDuration(value);
  DecayGen->setStartLevel(1.0);
  DecayGen->setEndLevel(SustainGen->tick());
}

void ADSRGen::setSustain(float value) {
  SustainGen->control("value", value);
  SustainGen->control("gate", 1.0); // send value

}
void ADSRGen::setRelease(float value) {
  ReleaseGen->setDuration(value);
  ReleaseGen->setStartLevel(SustainGen->tick());
  ReleaseGen->setEndLevel(0.0);
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
