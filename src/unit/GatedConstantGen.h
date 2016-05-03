#ifndef _GATED_CONSTANT_GEN_h_
#define _GATED_CONSTANT_GEN_h_

#include <stdlib.h>
#include "UGen.h"

namespace unit {

  /**
   * GatedConstantGen erzeugt einen konstanten Wert in Abhängigkeit von
   * dem gesetzten gate-Wert.
   
   * - Ist der gate-Wert größer oder gleich 1, liefert tick() den Wert von 
   * **amnt1**, 
   * - andernfalls **0**. 
   * - Der gate-wert wird in **amnt2** gespeichert.
   *
   * Control-Interface
   * 
   * - control("value", value) setzt den zu erzeugenden konstanten Wert
   * - control("gate", value) setzt den gate-Wert. 
   *
   * @author jtm
   * @since 04-2016
   * @version 1.0
   **/

  class GatedConstantGen : public UGen {

  public:
    GatedConstantGen();
    GatedConstantGen(std::string name);

    void control(std::string portName, float value);
    float tick();

    void setLevel(float value);
    void setGate(float value);


  private:
    bool isGated;
  
  };
}


#endif
