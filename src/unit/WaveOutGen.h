#ifndef _WAVE_OUT_GEN_h_
#define _WAVE_OUT_GEN_h_

#include <stdlib.h>    
#include "UGen.h"
#include "util/Interpolation.h"
#include "util/WaveWriter.h"

namespace unit {
  class WaveOutGen: public UGen {

  public:
    WaveOutGen();
    WaveOutGen(std::string name);

    void control(std::string portName, float value);
    float tick(); // override standard implementation
    long count = 0;

  private:
    std::string fname;
    WaveWriter waveWriter;
    bool doRecord = false;
    bool isOpen = false;
    bool isClosed = true;

  };
}

#endif
