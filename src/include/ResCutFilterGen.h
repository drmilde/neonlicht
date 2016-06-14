#ifndef _RES_CUT_FILTER_GEN_h_
#define _RES_CUT_FILTER_GEN_h_

#include <iostream>    
#include <stdlib.h>    
#include <math.h>    
#include "UGen.h"
#include "Interpolation.h"

namespace unit {
  /**
   * ResCutFilterGen is approximating the 4 ladder Moog lowpass.
   * Type : 24db resonant lowpass
   * References : CSound source code, Stilson/Smith CCRMA paper.
   *
   * Filtering the in port **in1**, **out1** stores the output value. 
   *
   * - **tick()** is providing the filtered input value.
   *
   * Control-Interface
   *
   * - **control("cutoff", value)**: [0-1] is mapped to [20-22050]
   * - **control("resonance", value)**: [0-1] is mapped to [0-1]
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
  class ResCutFilterGen: public UGen {

  public:
    ResCutFilterGen();
    ResCutFilterGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);

    void setCutoff(float v);
    void setResonance(float v);

  protected:
    float cutoff; // cutoff freq in Hz
    float res;    // resonance [0 - 1] (minimum - maximum)
    
  };
}

#endif
