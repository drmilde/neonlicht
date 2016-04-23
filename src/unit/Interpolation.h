#ifndef _INTERPOLATION_h_
#define _INTERPOLATION_h_

class Interpolation {

 public:
  static float map (float value, float s1, float e1, float s2, float e2);
  static float map (int value, int s1, int  e1, float s2, float e2);
  static int discrete (float value, float s1, float e1, int max);
};


#endif
