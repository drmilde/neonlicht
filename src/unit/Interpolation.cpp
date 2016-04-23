#include "Interpolation.h"

float Interpolation::map (float value, float s1, float e1, float s2, float e2) {
  if (s1 == e1)
    return 0.0;
  return ((value-s1) / (e1-s1) * (e2-s2)) + s2;
}

float Interpolation::map (int value, int s1, int e1, float s2, float e2) {
  if (s1 == e1)
    return 0.0;
  return ((value-s1) / ((float)(e1-s1)) * (e2-s2)) + s2;
}

int Interpolation::discrete (float value, float s1, float e1, int max) {
  float v = map(value, s1, e1, 0, 1); // repmapping auf [0,1]
  return ((int)(v * (max+1)));
}
