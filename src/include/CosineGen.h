#ifndef _COSINE_GEN_h_
#define _COSINE_GEN_h_

#include "SawGen.h"
#include "CosineTable.h"

namespace unit {
  /**
   * CosineGen is generating a cosine wave form based on a cosine 
   * wave table. 
   * 
   * The saw wave form is transformed into a ramp [0,1] and used as
   * a normalized index into the wave table.
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
