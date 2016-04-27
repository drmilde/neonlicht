#ifndef _THRESHOLD_GEN_h_
#define _THRESHOLD_GEN_h_

#include <stdlib.h>
#include <math.h>      
#include "UGen.h"

namespace unit {

/**
 * ThresholdGen testet, ob der Absolutwert des aktuellen Samplewertes
 * größer ist als der gesetzte Schwellwert.
 * Falls ja, liefert tick() 1.0 zurück, ansonsten 0.0.
 * Der Schwellwert muss im Interval [0,1] liegen. Dies wird nicht
 * geprüft.
 *
 * - control("in1", value) setzt den akuellen **Samplewert**.
 * - control("threshold", value) setzt den **Schwellwert**.
 *
 * @author jtm
 * @since 04-2016
 * @version 1.0
 **/

  class ThresholdGen: public UGen {

  public:
    ThresholdGen();
    ThresholdGen(std::string name);
  
    void control(std::string portName, float value);  
    float tick(); // override standard implementation
  
  };
}

#endif
