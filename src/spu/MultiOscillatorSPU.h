#ifndef _MULTI_OSCILLATOR_SPU_h_
#define _MULTI_OSCILLATOR_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "unit/NumberGen.h"
#include "unit/PulseGen.h"
#include "unit/SawGen.h"
#include "unit/SquareGen.h"
#include "unit/CosineGen.h"
#include "unit/NoiseGen.h"
#include "unit/MultiSwitch5Gen.h"

class MultiOscillatorSPU : public ArturiaMiniLabUnit {
 public:
  
  MultiOscillatorSPU();
  MultiOscillatorSPU(std::string name);
  float tick();
  void control(std::string portName, float value);

  // fast access function
  void setFrequencyMod(float value);
  void setPulseWidthMod(float value);

 private:
  void setOscillatorFreq(float value);
  void selectOscillator (float value);

  // UGens used
  unit::NumberGen* frequency;
  unit::NumberGen* frequencyMod;
  unit::NumberGen* pulseWidth;
  unit::NumberGen* pulseWidthMod;
  unit::NumberGen* select;
  
  unit::PulseGen* pulse;
  unit::CosineGen* cosine;
  unit::SawGen* saw;
  unit::NoiseGen* noise;
  unit::SquareGen* square;

  unit::MultiSwitch5Gen* oscillatorSwitch;

};


#endif
