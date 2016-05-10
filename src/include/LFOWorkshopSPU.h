#ifndef _LFO_WORKSHOP_SPU_h_
#define _LFO_WORKSHOP_SPU_h_

#include "MultiOscillatorSPU.h"

/**
 * LFOWorkshopSPU provides a simple LFO for the WorkshopSPU.
 * It is derived from MultiOscillatorSPU, and provides
 * the same wave forms.
 * 
 *
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
class LFOWorkshopSPU : public MultiOscillatorSPU {
 public:
  
  LFOWorkshopSPU();
  LFOWorkshopSPU(std::string name);
  float tick();
  void control(std::string portName, float value);
    
};


#endif
