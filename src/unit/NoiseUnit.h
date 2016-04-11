#ifndef _NOISE_UNIT_h_
#define _NOISE_UNIT_h_

#include <string>
#include <math.h>
#include <chrono>


#include "SoundUnit.h"
#include "NoiseGen.h"
#include "SawGen.h"
#include "PhasorGen.h"
#include "SquareGen.h"
#include "OnePoleLPFGen.h"
#include "TwoInputMixerGen.h"
#include "EGUpDownGen.h"
#include "WaveOutGen.h"
#include "EGOneStepGen.h"
#include "ADSRGen.h"

#include "STKOneZeroGen.h"
#include "STKTwoPoleGen.h"
#include "STKTwoZeroGen.h"
#include "STKBiQuadGen.h"
#include "STKOnePoleGen.h"

class NoiseUnit : public SoundUnit {

 public:
  NoiseUnit();

  // have to be implemented
  void setup();
  void control(std::string portName, float value);
  float tick();

 private:
  unit::NoiseGen* noise1;
  unit::NoiseGen* noise2;
  unit::SawGen* saw1;
  unit::PhasorGen* phasor1;
  unit::SquareGen* square1;
  unit::EGUpDownGen* eg1;
  unit::OnePoleLPFGen* onelpf;
  unit::TwoInputMixerGen* mixer1;
  unit::TwoInputMixerGen* mixer2;
  unit::EGOneStepGen* oneStepEG;

  unit::STKOneZeroGen* stkOneZero;
  unit::STKTwoPoleGen* stkTwoPole;
  unit::STKTwoZeroGen* stkTwoZero;
  unit::STKBiQuadGen* stkBiQuad;
  unit::STKOnePoleGen* stkOnePole;

  unit::WaveOutGen* waveOut;
  unit::ADSRGen* adsr1;

};


#endif
