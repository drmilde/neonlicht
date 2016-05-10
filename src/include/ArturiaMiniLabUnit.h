#ifndef _ARTURIA_MINILAB_UNIT_h_
#define _ARTURIA_MINILAB_UNIT_h_

#include <string>

#include "MessageData.h"
#include "SoundUnit.h"

/**
 * ArturiaMiniLabUnit provides an adapter to the 
 * Arturia MiniLab controller. 
 * All keys, knobs, pads and sliders are mapped to control calls.
 *
 * The Unit will later be replaced by a generic hardware abstraction
 * unit, that loads the mapping information from a configuraiton
 * file. 
 *
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
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
