#ifndef _VCO_MOD_SPU_h_
#define _VCO_MOD_SPU_h_

#include "ArturiaMiniLabUnit.h"

#include "NumberGen.h"

class VCOModSPU : public ArturiaMiniLabUnit {
 public:
  
  VCOModSPU();
  VCOModSPU(std::string name);
  float tick();
  void control(std::string portName, float value);

  // fast access function
  void setEGInput(float value);
  void setLFOInput(float value);
  
  void setSourceSelect(float value);
  void setDestSelect(float value);
  
  void setAmount(float value);
  
  float getPWMValue();
  float getFreqValue();


 private:    
  // UGens used
  unit::NumberGen* sourceSelect;
  unit::NumberGen* egInputValue;
  unit::NumberGen* lfoInputVal;
  unit::NumberGen* amount;
  unit::NumberGen* destSelect;
  unit::NumberGen* pwmOuputValue;
  unit::NumberGen* freqOutputVal;
  
};


#endif
