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
   *
   * mixing the in ports **in1** and **in2**. Both values are
   * scaled by **amnt1** and **amnt2**. 
   * The mixer is calculating z = (in1 * amnt1) + (in2 * amnt2).
   * The in ports amnt1 and amnt1 are scaled by **0.5f** when being set with the control
   * interface.
   *
   * - **tick()** is providing the filtered input value.
   *
   * Control-Interface
   *
   * - **control("amnt1", value)**: stores the value in amnt1. 
   * - **control("amnt2", value)**: stores the value in amnt2. 
   *
   * Fast access functions
   * - none, but the standard fast access functions
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
