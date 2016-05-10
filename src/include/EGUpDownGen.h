#ifndef _EG_UP_DOWN_GEN_h_
#define _EG_UP_DOWN_GEN_h_


#include <stdlib.h>    
#include "EnvelopeGen.h"
#include "Interpolation.h"

namespace unit {
  /**
   * EGUpDownGen generates a simple symetrical up/down envelope.
   * 
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class EGUpDownGen: public EnvelopeGen {

  public:
    EGUpDownGen();
    EGUpDownGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);

  private:
    void reset();
  
    Port durationPort;
    Port triggerPort;
    Port outPort;

    float duration; // in seconds
    int numberTicks;
    int currentTick;
    bool up;
  
  };
}

#endif
