#ifndef _ADSR_WORKSHOP_SPU_h_
#define _ADSR_WORKSHOP_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "NumberGen.h"
//#include "unit/ADSRGen.h"
#include "ADSR-NewGen.h"

class ADSRWorkshopSPU : public ArturiaMiniLabUnit {
 public:
  
  ADSRWorkshopSPU();
  ADSRWorkshopSPU(std::string name);
  float tick();
  void control(std::string portName, float value);

  // fast access function
  void setTrigger();
  void setGate(float value);


 private:    
  // UGens used
  unit::NumberGen* attack;
  unit::NumberGen* decay;
  unit::NumberGen* sustain;
  unit::NumberGen* release;
  unit::NumberGen* useSustain;

  unit::ADSR_NewGen* adsr;  
};


#endif
