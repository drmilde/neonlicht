#ifndef _THRESHOLD_GEN_h_
#define _THRESHOLD_GEN_h_

#include <stdlib.h>
#include <math.h>      
#include "UGen.h"

namespace unit {

/**
 * ThresholdGen testet, ob der aktuelle Samplewert (gespeichert in **in1**)
 *
 * - größer ist als der Absolutwert des gesetzten Schwellwerts, 
 * falls ja, liefert tick() **1.0** zurück, 
 *
 * - ansonsten ob der Samplewert kleiner als der der negative Absolutwert
 * des gesetzten Schwellwerts ist,  
 * falls ja, liefert tick() - **1.0** zurück, 
 *
 * - ansonsten **0.0**.
 *
 * Der Schwellwert sollte im Interval [-1,1] liegen. Dies wird nicht
 * geprüft.
 *
 * Control-Interface
 * 
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
