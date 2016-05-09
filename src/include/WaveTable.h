#ifndef _WAVE_TABLE_h_
#define _WAVE_TABLE_h_

#include "Interpolation.h"

class WaveTable {
 public:
  WaveTable();
  float get(int idx);
  float getNormedIdx(float value);
  virtual void init() = 0;
  
 protected:
  static const int TABLE_SIZE = 2048;
  float table[TABLE_SIZE] = {};
  
 private:
  void clear();
  
   
};

#endif
