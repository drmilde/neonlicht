#ifndef _MULTI_OSCILLATOR_SPU_h_
#define _MULTI_OSCILLATOR_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "NumberGen.h"
#include "PulseGen.h"
#include "SawGen.h"
#include "SquareGen.h"
#include "CosineGen.h"
#include "NoiseGen.h"
#include "MultiSwitch5Gen.h"

/**
 * MultiOscillatorSPU provides a selectable multi oscillator
 * providing all of the available oscillators.
 *
 * Currently (9.5.2016) these are: PulseGen, SawGen, CosineGen, 
 * SquareGen, and NoiseGen. 
 * 
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
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
