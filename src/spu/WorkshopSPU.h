#ifndef _WORKSHOP_SPU_h_
#define _WORKSHOP_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "spu/MultiOscillatorSPU.h"
#include "spu/LFOWorkshopSPU.h"

#include "unit/NumberGen.h"
#include "unit/MidiInputGen.h"
#include "unit/ADSRGen.h"
#include "unit/WaveOutGen.h"
#include "util/MidiUtil.h"

class WorkshopSPU : public ArturiaMiniLabUnit {
 public:
  WorkshopSPU();
  float tick();
  void control(std::string portName, float value);

 private:

  // UGens used
  unit::NumberGen* lfoAmnt;
  unit::MidiInputGen* midiin;
  unit::ADSRGen* adsr;

  // SPU building blocks of Workshop
  MultiOscillatorSPU* vco;
  LFOWorkshopSPU* lfo;

  unit::WaveOutGen* waveOut;

};


#endif
