#ifndef _WAVE_WRITER_h_
#define _WAVE_WRITER_h_

#include "RtWvIn.h"
#include "FileWvOut.h"
#include <cstdlib>

class WaveWriter {

 public:
  WaveWriter();
  WaveWriter(std::string fname);
  ~WaveWriter();

  void open(std::string fname);
  void close();
  void write(float value);

 private:
  stk::FileWvOut *output = 0;
    
};

#endif
