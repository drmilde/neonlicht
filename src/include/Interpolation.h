#ifndef _INTERPOLATION_h_
#define _INTERPOLATION_h_

#include <iostream>
#include <math.h>

class Interpolation {

 public:
  static float map (float value, float s1, float e1, float s2, float e2);
  static float map (int value, int s1, int  e1, float s2, float e2);
  static int discrete (float value, float s1, float e1, int max);


  /**
   *
   * Calculates the logarithm() of the linear mapping of 
   * the input value from interval [s1,e1] to interval [s2,e2].
   *
   * - The logarithmic result allows for a more fine grained
   * control of the **higher** end of the interval.
   *
   * - The result should be normalized by dividing the result by log(e2-s2).
   * 
   * @returns The log() of the linear mapping.
   *
   * @param value: the value to be mapped (e.g. a knob value)
   * @param s1: start of domain interval
   * @param e1: end of domain interval
   * @param s2: start of range interval
   * @param e2: end of range interval
   *
   *
   **/
  static float maplog (float value, float s1, float  e1, float s2, float e2);
  static float mapexp (float value, float s1, float  e1, float s2, float e2);
};


#endif
