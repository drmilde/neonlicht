#ifndef _NOISE_UNIT_h_
#define _NOISE_UNIT_h_

#include <string>
#include <math.h>
#include <chrono>

#include "osc/MessageData.h"

#include "unit/SoundUnit.h"
#include "unit/NoiseGen.h"
#include "unit/SawGen.h"
#include "unit/PhasorGen.h"
#include "unit/CosineGen.h"
#include "unit/SquareGen.h"
#include "unit/OnePoleLPFGen.h"
#include "unit/TwoInputMixerGen.h"
#include "unit/EGUpDownGen.h"
#include "unit/WaveOutGen.h"
#include "unit/EGOneStepGen.h"
#include "unit/ADSRGen.h"
#include "unit/MidiInputGen.h"

#include "unit/STKOneZeroGen.h"
#include "unit/STKTwoPoleGen.h"
#include "unit/STKTwoZeroGen.h"
#include "unit/STKBiQuadGen.h"
#include "unit/STKOnePoleGen.h"

class NoiseUnit : public unit::SoundUnit {

 public:
  NoiseUnit();

  // have to be implemented
  void setup();
  float tick();
  void processMidiMessage(int type, int key, float value);
  void processControlMessage(int type, int key, float value);

 private:
  // has to be implemented
  void control(std::string portName, float value);

  // UGens used by this SPU
  unit::NoiseGen* noise1;
  unit::NoiseGen* noise2;
  unit::SawGen* saw1;
  unit::PhasorGen* phasor1;
  unit::CosineGen* cosine1;
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

  unit::MidiInputGen* midiInput1;
   
};


#endif
