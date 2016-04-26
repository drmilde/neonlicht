#include "MidiInputGen.h"

using namespace unit;

MidiInputGen::MidiInputGen() : MidiInputGen("Gates of heaven") {
}

MidiInputGen::MidiInputGen(std::string name) : UGen(name, 0) {
  // do something useful here
}

void MidiInputGen::control (std::string portName, float value) {
  if (portName == "midi on") { // key
    setAmnt1(value); // key
    midiOnCount++;
    triggerCount = 1; // keep trigger for one tick. Do I need more cycles ?
  }

  if (portName == "midi off") { // key
    // TODO match pairing key ... currently it is ignored
    midiOnCount--;
    midiOnCount = std::max(midiOnCount, 0); // limit to 0;
  }

  if (portName == "velocity") { // velocity
    setAmnt2(value);
  }
  
  if (portName == "reset") { // reset, if hanging midi events
    midiOnCount = 0;
    triggerCount = 0;
  }
  
}


// overrides tick() in UGen
float MidiInputGen::tick() {
  // calculate the values

  if (midiOnCount > 0) { // set gate
    setOut1(1.0);
  } else {
    setOut1(0.0);
  }

  if (triggerCount > 0) { // trigger was set in last tick, reset to 
    setOut2(1.0); // set trigger
    triggerCount--;
    triggerCount = std::max(triggerCount, 0); // limit minimum to 0;
  } else {
    setOut2(0.0);
  }

  // return current tick() value
  // return the current key / last key that has been set
  return getAmnt1();
}

