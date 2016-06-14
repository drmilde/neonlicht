#ifndef _MOOG_VCF_v2_GEN_h_
#define _MOOG_VCF_v2_GEN_h_

#include "ResCutFilterGen.h"

namespace unit {
  /**
   * MoogVCFv2Gen is approximating the 4 ladder Moog lowpass.
   * Type : 24db resonant lowpass
   * References : CSound source code, Stilson/Smith CCRMA paper., 
   * Timo Tossavainen (?) version
   *
   * Filtering the in port **in1**, **out1** stores the output value. 
   *
   * - **tick()** is providing the filtered input value.
   *
   * Control-Interface
   *
   * - **control("cutoff", value)**: [0-1] is mapped to [20-22050]
   * - **control("resonance", value)**: [0-1] is mapped to [0-4]
   *
   * Fast access functions
   * - setCutoff(float v);
   * - setResonance(float v);
   * - the standard fast access functions
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class MoogVCFv2Gen: public ResCutFilterGen {

  public:
    MoogVCFv2Gen();
    MoogVCFv2Gen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);
    
    void setCutoff(float v);
    void setResonance(float v);
    

  private:
    void update();
 
    float f;
    float fb;

    float in1;
    float in2;
    float in3;
    float in4;
    float out1;
    float out2;
    float out3;
    float out4;
  };
}

#endif
