#include "WaveTable.h"

WaveTable::WaveTable() {
  clear();
}

void WaveTable::clear() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    table[i] = 0.0;
  }
}

float WaveTable::get(int idx) {
  return table[idx%TABLE_SIZE];
}

float WaveTable::getNormedIdx(float value) {
  int idx = (int)(Interpolation::map (value, 0.0, 1.0, 0, TABLE_SIZE));
  return (table[idx%TABLE_SIZE] + table[(idx-1)%TABLE_SIZE]) / 2;
}
  
   
