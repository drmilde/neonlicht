#include "VCOModSPU.h"


VCOModSPU::VCOModSPU() : VCOModSPU("VCOModSPU") {
  // do something useful here
}

VCOModSPU::VCOModSPU(std::string name) : ArturiaMiniLabUnit(name) {
   // State/Interface of the SPU
  egInputValue = new unit::NumberGen("ed input");
  setEGInput(0.0);

  lfoInputVal = new unit::NumberGen("lfo input");
  setLFOInput(0.0);

  sourceSelect = new unit::NumberGen("source select");
  setSourceSelect(0.0);

  amount = new unit::NumberGen("amount");
  setAmount(0.0);

  pwmOuputValue = new unit::NumberGen("pwm output");
  pwmOuputValue->setValue(0.0);

  freqOutputVal = new unit::NumberGen("freq output");
  freqOutputVal->setValue(0.0);

  destSelect = new unit::NumberGen("dest select");
  setDestSelect(0.0);
}


void VCOModSPU::control(std::string portName, float value) {
  if (portName == "select eg") {
    setSourceSelect(0);
  }
  if (portName == "select lfo") {
    setSourceSelect(1);
  }
  
  if (portName == "amount") {
    setAmount(value);
  }
  
  if (portName == "select pwm") {
    setDestSelect(0);
  }
  if (portName == "select freq") {
    setDestSelect(1);
  }
}


// fast access functions
void VCOModSPU::setEGInput(float value) {
  egInputValue->setValue(value);
}
void VCOModSPU::setLFOInput(float value) {
  lfoInputVal->setValue(value);
}

void VCOModSPU::setSourceSelect(float value) {
  sourceSelect->setValue(((int)value)%2);
}

void VCOModSPU::setDestSelect(float value) {
  destSelect->setValue(((int)value)%2);
}

void VCOModSPU::setAmount(float value) {
  amount->setValue(value);
}

float VCOModSPU::getPWMValue() {
  return pwmOuputValue->tick();
}

float VCOModSPU::getFreqValue() {
  freqOutputVal->tick();
}


// generate the sample

float VCOModSPU::tick() {
  // calculate output value

  float val = 0.0;

  if ((sourceSelect->tick()) < 1) { // eg selected
    val = egInputValue->tick();
  } else {
    val = lfoInputVal->tick(); // lfo selcted
  }

  val = val * amount->tick(); // multiply input value with amount

  if ((destSelect->tick()) < 1) { // pwm selected
    pwmOuputValue->setValue(val);
    freqOutputVal->setValue(0.0);
  } else { // freq selected
    pwmOuputValue->setValue(0.0);
    freqOutputVal->setValue(val);
  }
  
  
  return val;
}
