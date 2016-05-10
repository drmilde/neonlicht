#ifndef _WAVE_TABLE_h_
#define _WAVE_TABLE_h_

#include "Interpolation.h"

/**
 * WaveTable is the base class for all wave table based oscillators.
 *
 * Access to the values is provided through 

 * - **get(int idx)**: a cyclic integer index, or through 
 * - **getNormedIdx(float idx)**: a cyclic normalized  
 * float index in the range [0,1].
 * 
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
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
