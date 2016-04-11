#ifndef _OSC_ACTIVATOR_h_
#define _OSC_ACTIVATOR_h_


#include <iostream>

#include "Activator.h"
#include "osc/OscOutConnector.h"

class OscActivator : public Activator {

 public:
  OscActivator();

  void callback(float value);

 private:
  osc::OscOutConnector oscOut;
  int note;

  //int littleMelody[8] = {53, 55, 57, 58, 60, 58, 57, 55};
  int littleMelody[16] = {53, 57, 57, 57, 53, 57, 58, 55, 48, 52, 52, 52, 48, 52, 53, 50};
  int noteIdx = 0;
};

#endif
