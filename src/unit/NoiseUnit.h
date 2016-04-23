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
  NoiseGen* noise1;
  NoiseGen* noise2;
  SawGen* saw1;
  PhasorGen* phasor1;
  SquareGen* square1;
  EGUpDownGen* eg1;
  OnePoleLPFGen* onelpf;
  TwoInputMixerGen* mixer1;
  TwoInputMixerGen* mixer2;
  EGOneStepGen* oneStepEG;

  STKOneZeroGen* stkOneZero;
  STKTwoPoleGen* stkTwoPole;
  STKTwoZeroGen* stkTwoZero;
  STKBiQuadGen* stkBiQuad;
  STKOnePoleGen* stkOnePole;

  WaveOutGen* waveOut;
  ADSRGen* adsr1;

};


#endif
