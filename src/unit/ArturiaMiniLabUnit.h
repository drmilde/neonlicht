#ifndef _ARTURIA_MINILAB_UNIT_h_
#define _ARTURIA_MINILAB_UNIT_h_

#include <string>

#include "osc/MessageData.h"
#include "SoundUnit.h"

class ArturiaMiniLabUnit : public unit::SoundUnit {

 public:
  ArturiaMiniLabUnit();
  ArturiaMiniLabUnit(std::string name);

  // have to be implemented
  void setup();
  float tick();
  void processMidiMessage(int type, int key, float value);
  void processControlMessage(int type, int key, float value);

 private:
  // has to be implemented
  void control(std::string portName, float value);
   
};


#endif
