#ifndef _COSINE_TABLE_h_
#define _COSINE_TABLE_h_

#include "WaveTable.h"
#include <math.h>

/**
 * CosineTable stores the cosine values for x in [0, 2*pi].
 *
 * Currently no interpolation between values is calculated. The
 * table size is defined for the base class WaveTable. 
 *
 * Access to the values is provided through 
 *
 * - **get(int idx)**: a cyclic integer index, or through 
 * - **getNormedIdx(float idx)**: a cyclic normalized  
 * float index in the range [0,1].
 * 
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
class CosineTable : public WaveTable {
 public:
  CosineTable();
  void init();
   
};

#endif
