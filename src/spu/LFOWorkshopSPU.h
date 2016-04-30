#ifndef _LFO_WORKSHOP_SPU_h_
#define _LFO_WORKSHOP_SPU_h_

#include "MultiOscillatorSPU.h"

class LFOWorkshopSPU : public MultiOscillatorSPU {
 public:
  
  LFOWorkshopSPU();
  LFOWorkshopSPU(std::string name);
  float tick();
  void control(std::string portName, float value);
    
};


#endif
