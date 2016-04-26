#ifndef _MIDI_INPUT_GEN_h_
#define _MIDI_INPUT_GEN_h_

#include <iostream>    
#include <stdlib.h>    
#include <algorithm>
#include "UGen.h"

namespace unit {
  class MidiInputGen: public UGen {

  public:
    MidiInputGen();
    MidiInputGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);

  private:
    int midiOnCount = 0;
    int triggerCount = 0;
     
  };
}

#endif
