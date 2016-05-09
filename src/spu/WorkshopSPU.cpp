#include "WorkshopSPU.h"

WorkshopSPU::WorkshopSPU() : ArturiaMiniLabUnit("The German Workshop") {
  // do something useful here
  lfoAmnt = new unit::NumberGen("lfo amnt");
  lfoAmnt->control("lfo amnt", 0.0);
 
  vco = new MultiOscillatorSPU("multi osc 0");

  lfo = new LFOWorkshopSPU("lfo 0");
  lfo->control("frequency", 0.0);
  lfo->control("select triangle", 1.0);

  midiin = new unit::MidiInputGen("midiin");
  adsr = new ADSRWorkshopSPU("adsr");
}

WorkshopSPU::~WorkshopSPU() {
  delete lfoAmnt;
  delete lfo;
  delete vco;
  delete midiin;
  delete adsr;
}

void WorkshopSPU::control(std::string portName, float value) {

  // process keys
  if (portName == "midi on") {
    midiin->control("midi on", value);
    vco->control("frequency", util::MidiUtil::midi2frequency(int(value)));
  }
  if (portName == "midi off") {
    midiin->control("midi off", value);
  }
  if (portName == "velocity") {
    midiin->control("velocity", value);
  }
  
  // control parameters of the SPUs
  if (portName == "param 1") {
    vco->control("frequency", value * 880.0);
  }
  if (portName == "param 2") {
    vco->control("pwm", value);
  }
  if (portName == "lfo rate") {
    lfo->control("frequency", value * 10.0);
  }
  if (portName == "lfo amnt") {
    lfoAmnt->control("lfoamnt", value);
  }
  if (portName == "pad 13") { // AAAARGH, midi hangs
    midiin->control("reset", 1);
  }
  if (portName == "pad 14") { // flip through the oscillators of vco
    vco->control("next osc", value);
  }
  if (portName == "pad 15") {
    lfo->control("select triangle", 1.0);
  }
  if (portName == "pad 16") {
    lfo->control("select square", 1.0);
  }

  // adsr
  if (portName == "attack") {
    adsr->control("attack", value);
  }
  if (portName == "decay") {
    adsr->control("decay", value);
  }
  if (portName == "sustain") {
    adsr->control("sustain", value);
  }
  if (portName == "release") {
    adsr->control("attack", value);
  }


}


float WorkshopSPU::tick() {
  midiin->tick(); // midi input

  if (midiin->getTrigger() > 0) {
    adsr->setTrigger(); // start the adsr
  }

  if (midiin->getGate() > 0) {
    //vco->setPulseWidthMod(lfo->tick() * 1.2);
    vco->setFrequencyMod(1.0 + (lfo->tick() * lfoAmnt->tick())); // berechne und setzt modulierte Frequenz
  }
  
  setOut1(vco->tick()); // speichere den aktuellen sample wert
  
  adsr->setGate(midiin->getGate()); // set gate in adsr

  return getOut1()*adsr->tick(); 
}
