#ifndef _MY_UNIT_h_
#define _MY_UNIT_h_

#include "ArturiaMiniLabUnit.h"

#include "unit/CosineGen.h"
#include "unit/PulseGen.h"
#include "unit/WaveOutGen.h"

class MyUnit : public ArturiaMiniLabUnit {
 public:
  MyUnit();
  float tick();
  void control(std::string portName, float value);

 private:

  // UGens used
  unit::PulseGen* pulse1;
  unit::WaveOutGen* waveOut;

  unit::CosineGen* lfo1;

  // current frequency of this unit
  float frequency;

};


#endif
