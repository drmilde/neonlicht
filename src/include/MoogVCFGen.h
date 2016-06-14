#ifndef _MOOG_VCF_GEN_h_
#define _MOOG_VCF_GEN_h_

#include <iostream>    
#include <stdlib.h>    
#include <math.h>    
#include "UGen.h"
#include "Interpolation.h"

namespace unit {
  /**
   * MoogVCFGen is approximating the 4 ladder Moog lowpass.
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
  class MoogVCFGen: public UGen {

  public:
    MoogVCFGen();
    MoogVCFGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);

    void setCutoff(float v);
    void setResonance(float v);

  private:
    float cutoff; // cutoff freq in Hz
    float fs;     // sampling frequency //(e.g. 44100Hz)
    float res;    // resonance [0 - 1] (minimum - maximum)

    float f; // [0 - 1]
    float k; //(Empirical tunning)
    float p;
    float scale;
    float r;

    float y1;
    float y2;
    float y3;
    float y4;
    float oldx;
    float oldy1;
    float oldy2;
    float oldy3;
    
  };
}

#endif
