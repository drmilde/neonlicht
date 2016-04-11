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


float Interpolation::mapexp (float value, float s1, float e1, float s2, float e2) {
  if (s1 == e1)
    return 0.0;
  
  float s2_linear = 0.0;
  if (s2 > 0)  {
    s2_linear = log(s2); // transform to linear value
  }

  float e2_linear = 0.0;
  if (e2 > 0)  {
    e2_linear = log(e2); // transform to linear value
  }

  return (exp(Interpolation::map (value, s1, e1, s2_linear, e2_linear))); // return to exponential space
  
}

float Interpolation::maplog (float value, float s1, float e1, float s2, float e2) {
  if (s1 == e1)
    return 0.0;
  
  float val = Interpolation::map (value, s1, e1, s2, e2); // linear interpolation

  if (val > 0) {
    return log(val); // transform to logarithmic space
  } else {
    return 0.0;
  }
   
}



int Interpolation::discrete (float value, float s1, float e1, int max) {
  float v = map(value, s1, e1, 0, 1); // repmapping auf [0,1]
  return ((int)(v * (max+1)));
}
