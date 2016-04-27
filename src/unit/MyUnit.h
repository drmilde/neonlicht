#ifndef _MY_UNIT_h_
#define _MY_UNIT_h_

#include "ArturiaMiniLabUnit.h"

#include "unit/CosineGen.h"
#include "unit/ThresholdGen.h"
#include "unit/WaveOutGen.h"

class MyUnit : public ArturiaMiniLabUnit {
 public:
  MyUnit();
  float tick();
  void control(std::string portName, float value);

 private:

  // UGens used
  unit::CosineGen* cosine1;
  unit::ThresholdGen* threshold1;
  unit::WaveOutGen* waveOut;

};


#endif
