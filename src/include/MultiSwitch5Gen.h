#ifndef _MULTI_SWITCH_5_GEN_h_
#define _MULTI_SWITCH_5_GEN_h_

#include <stdlib.h>
#include "UGen.h"

namespace unit {

  /**
   * MultiSwitch5Gen switches between 5 inputs (in1 - in5)
   *
   * Control-Interface
   * 
   * - control("select", value) setzt den select-Wert [0,1,2,3,4]
   *
   * @author jtm
   * @since 04-2016
   * @version 1.0
   **/

  class MultiSwitch5Gen : public UGen {

  public:
    MultiSwitch5Gen();
    MultiSwitch5Gen(std::string name);

    void control(std::string portName, float value);
    float tick();
    void setSelect(float value);

    // additional in ports
    void setIn4(float value);
    void setIn5(float value);  
    float getIn4();
    float getIn5();

  private:
    bool isGated;
    float in4;
    float in5;

    int select = 0;
  
  };
}


#endif
