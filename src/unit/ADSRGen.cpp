#include "ADSRGen.h"


ADSRGen::ADSRGen() : ADSRGen("") {
}

ADSRGen::ADSRGen(std::string name) : UGen(name,1) {

  attack = 0.1;
  decay = 0.3;
  sustain = 0.5;
  release = 0.2;
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
  SustainGen->control("amnt1", sustain);
  SustainGen->control("amnt2", 1.0); // send value

  ReleaseGen = new EGOneStepGen("Sustain");
  ReleaseGen->setDuration(release);
  ReleaseGen->setStartLevel(sustain);
  ReleaseGen->setEndLevel(0.0);

  
  reset();
}

void ADSRGen::control(std::string portName, float value) {
  if (portName == "trigger") {
    reset();
    isTriggered = true;
  }

  if (portName == "gate") {
    gate = (value >= 1);
  }
}

void ADSRGen::reset() {
  state = IDLE;
  isTriggered = false;
  gate = false;

  AttackGen->reset(); // AN DIESER STELLE MUSS DER LASTVAL REIN, UM DEN OFFSET ZU SETZEN !!!!!!!
  DecayGen->reset();
  ReleaseGen->reset();
}

float ADSRGen::tick() {
  // step through the states of the ADSR

  switch (state) {
  case IDLE: { // waiting for trigger
    setOut1(lastval);
    
    if (isTriggered) { // ADSR trigger is set, switch to ATTACK
      isTriggered = false; // process trigger impulse
      AttackGen->control("trigger", 1.0); // trigger the AttackGen      
      
      state = ATTACK;
    }
    break;
  }
  case ATTACK: {
    if (!gate) { // key has been released
      state = RELEASE;
      ReleaseGen->control("trigger", 1.0); // trigger the ReleaseGen
    } else {
      
      // process attack interpolation
      setOut1(AttackGen->tick());
      if (AttackGen->finished()) { // ready with attack phase? then switch to DECAY;
	state = DECAY;
	DecayGen->control("trigger", 1.0); // trigger the DecayGen
      }
    }    
    break;
  }
  case DECAY: {
    if (!gate) { // key has been released
      state = RELEASE;
      ReleaseGen->control("trigger", 1.0); // trigger the ReleaseGen
    } else {
      
      // process decay interpolation
      setOut1(DecayGen->tick());
      if (DecayGen->finished()) { // ready with attack phase? then switch to SUSTAIN;
	state = SUSTAIN;
	SustainGen->control("amnt2", 1.0); // send sustain value
      }
      
    }
    break;
  }
  case SUSTAIN: {
    if (!gate) { // key has been released
      state = RELEASE;
      ReleaseGen->control("trigger", 1.0); // trigger the ReleaseGen
    } else {
      // process sustain hold      
      setOut1(SustainGen->tick()); // send out value, as long as ADSR gate is 1 (key is pressed
    }
    break;
  }
  case RELEASE: {
    // process release interpolation
    setOut1(ReleaseGen->tick()); // send out values, as long as key is pressed
    if (ReleaseGen->finished()) {
      reset(); // ready for next ADSR cycle
    }
    
    if (isTriggered) { // (another) key has been pressed
      // do something her, I dont really know what exactly :)
    }
    
    break;
  }
  }

  lastval =  getOut1(); // avoid zero drop, when playing fast notes
  
  return lastval;
}
