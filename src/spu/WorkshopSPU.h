#ifndef _WORKSHOP_SPU_h_
#define _WORKSHOP_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "spu/MultiOscillatorSPU.h"
#include "spu/LFOWorkshopSPU.h"
#include "spu/ADSRWorkshopSPU.h"

#include "unit/NumberGen.h"
#include "unit/MidiInputGen.h"
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

  // SPU building blocks of Workshop
  MultiOscillatorSPU* vco;
  LFOWorkshopSPU* lfo;
  ADSRWorkshopSPU* adsr;

  unit::WaveOutGen* waveOut;

};


#endif
