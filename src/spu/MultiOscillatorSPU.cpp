#include "MultiOscillatorSPU.h"


MultiOscillatorSPU::MultiOscillatorSPU() : MultiOscillatorSPU("MultiOscillatorSPU") {
  // do something useful here
}

MultiOscillatorSPU::MultiOscillatorSPU(std::string name) : ArturiaMiniLabUnit(name) {
   // State/Interface of the SPU
  frequency = new unit::NumberGen("frequency");
  frequency->control("frequency", 440.0);
  
  frequencyMod = new unit::NumberGen("frequencyMod");
  frequencyMod->control("frequencyMod", 1.0);
  
  pulseWidth = new unit::NumberGen("pulseWidth");
  pulseWidth->control("pwm", 0.5);

  pulseWidthMod = new unit::NumberGen("pulseWidthMod");
  pulseWidthMod->control("pwmMod", 1.0);
  
  select = new unit::NumberGen("selectOsc");
  select->control("selectOsc", 0);

  // init the oscillators
  
  pulse = new unit::PulseGen("pulse");
  saw = new unit::SawGen("saw");
  noise = new unit::NoiseGen("noise");
  cosine = new unit::CosineGen("cosine");
  square = new unit::SquareGen("square");
  setOscillatorFreq(frequency->tick());

  // init the MultiSwitch
  oscillatorSwitch = new unit::MultiSwitch5Gen();
}

void MultiOscillatorSPU::setOscillatorFreq(float value) {
  pulse->setFrequency(value);
  saw->setFrequency(value);
  cosine->setFrequency(value);
  square->setFrequency(value);  
}

void MultiOscillatorSPU::control(std::string portName, float value) {
  if (portName == "frequency") {
    frequency->control("frequency", value*880.0);
    setOscillatorFreq(frequency->tick());
  }
  if (portName == "pwm") {
    pulseWidth->control("pwm", value);
    pulse->setPulseWidth(pulseWidth->tick());
  }
  if (portName == "param 3") {
  }
  if (portName == "param 4") {
  }
  if (portName == "next osc") {
    if (value == 1) {
      select->control("selectOsc", ((int)(select->tick() + 1)%5));
      oscillatorSwitch->setSelect(select->tick());
    }
  }
  if (portName == "pad 16") {
  }
}


void MultiOscillatorSPU::setPulseWidthMod(float value) {
    pulseWidthMod->setValue(value);
}

void MultiOscillatorSPU::setFrequencyMod(float value) {
  frequencyMod->setValue(value);
}


float MultiOscillatorSPU::tick() {

  setOscillatorFreq(frequency->tick() * frequencyMod->tick()); // apply fm
  pulse->setPulseWidth(pulseWidth->tick() * pulseWidthMod->tick()); // modulate pulse width
  
  oscillatorSwitch->setIn1(pulse->tick());
  oscillatorSwitch->setIn2(saw->tick());
  oscillatorSwitch->setIn3(cosine->tick());
  oscillatorSwitch->setIn4(square->tick());
  oscillatorSwitch->setIn5(noise->tick());


  return oscillatorSwitch->tick();
}
