#include "ADSRWorkshopSPU.h"


ADSRWorkshopSPU::ADSRWorkshopSPU() : ADSRWorkshopSPU("ADSRWorkshopSPU") {
  // do something useful here
}

ADSRWorkshopSPU::ADSRWorkshopSPU(std::string name) : ArturiaMiniLabUnit(name) {
   // State/Interface of the SPU
  attack = new unit::NumberGen("attack");
  attack->setValue(0.1);

  decay = new unit::NumberGen("decay");
  decay->setValue(0.3);

  sustain = new unit::NumberGen("sustain");
  sustain->setValue(0.4);

  release = new unit::NumberGen("release");
  release->setValue(1.0);

  // create adsr
  adsr = new unit::ADSRGen("adsr");
  adsr->setAttack(attack->tick());
}


void ADSRWorkshopSPU::control(std::string portName, float value) {
  if (portName == "attack") {
    attack->setValue(value);
    adsr->setAttack(attack->tick());
  }
  
  if (portName == "decay") {
    decay->setValue(value);
    adsr->setDecay(decay->tick());
  }
  
  if (portName == "sustain") {
    sustain->setValue(value);
    adsr->setSustain(sustain->tick());
  }
  
  if (portName == "release") {
    release->setValue(value);
    adsr->setRelease(release->tick());
  }
}


// fast access functions
void ADSRWorkshopSPU::setTrigger() {
  adsr->setTrigger();
}

void ADSRWorkshopSPU::setGate(float value) {
  adsr->setGate(value);
}


// generate the sample

float ADSRWorkshopSPU::tick() {
  // calculate output value  
  
  return adsr->tick();
}
