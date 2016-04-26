#include "CosineTable.h"

CosineTable::CosineTable() {
  init();
}

void CosineTable::init() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    float val = Interpolation::map (i, 0, TABLE_SIZE, 0, 2*M_PI);
    table[i] = cos(val);
  }
}
  
   
