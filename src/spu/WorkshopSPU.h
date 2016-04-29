#ifndef _WORKSHOP_SPU_h_
#define _WORKSHOP_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "spu/MultiOscillatorSPU.h"
#include "unit/NumberGen.h"
#include "unit/CosineGen.h"
#include "unit/WaveOutGen.h"

class WorkshopSPU : public ArturiaMiniLabUnit {
 public:
  WorkshopSPU();
  float tick();
  void control(std::string portName, float value);

 private:

  // UGens used
  unit::NumberGen* frequency;
  unit::NumberGen* pwm;
  unit::NumberGen* select;
  MultiOscillatorSPU* mosc;

  unit::CosineGen* lfo;
  unit::WaveOutGen* waveOut;

};


#endif
