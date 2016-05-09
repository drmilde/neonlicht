#ifndef _WORKSHOP_SPU_h_
#define _WORKSHOP_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "MultiOscillatorSPU.h"
#include "LFOWorkshopSPU.h"
#include "ADSRWorkshopSPU.h"

#include "NumberGen.h"
#include "MidiInputGen.h"
#include "WaveOutGen.h"
#include "MidiUtil.h"

class WorkshopSPU : public ArturiaMiniLabUnit {
 public:
  WorkshopSPU();
  virtual ~WorkshopSPU();
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
