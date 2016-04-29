#include "WorkshopSPU.h"


WorkshopSPU::WorkshopSPU() : ArturiaMiniLabUnit("The German Workshop") {
  // do something useful here

  frequency = new unit::NumberGen("frequency");
  select = new unit::NumberGen("select");
  select->control("select OSC", 0);

  mosc = new MultiOscillatorSPU("multi osc 0");

  lfo = new unit::CosineGen("lfo 1");
  lfo->control("frequency", 2.0);
  
}

void WorkshopSPU::control(std::string portName, float value) {
  if (portName == "param 1") {
    mosc->control("frequency", value);
  }
  if (portName == "param 2") {
    mosc->control("pwm", value);
  }
  if (portName == "param 3") {
  }
  if (portName == "pad 15") {
    mosc->control("next osc", value);
  }
  if (portName == "pad 16") {
  }
}


float WorkshopSPU::tick() {
  mosc->setPulseWidthMod(lfo->tick() * 1.2);
  return mosc->tick();
}
