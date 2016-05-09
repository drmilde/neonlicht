#ifndef _COSINE_GEN_h_
#define _COSINE_GEN_h_

#include "SawGen.h"
#include "CosineTable.h"

namespace unit {
  class CosineGen : public SawGen {
    
  public:
    CosineGen();
    CosineGen(std::string name);
    float tick();
    void control(std::string portName, float value);
    void setFrequency(float value);
    float getFrequency();
    
  private:
    CosineTable* cosine;
    
  };
}

#endif
