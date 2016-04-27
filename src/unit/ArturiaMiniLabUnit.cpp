#include "ArturiaMiniLabUnit.h"

ArturiaMiniLabUnit::ArturiaMiniLabUnit():ArturiaMiniLabUnit("ArturiaMiniLabUnit") {
}

ArturiaMiniLabUnit::ArturiaMiniLabUnit(std::string name): SoundUnit(name) {
  setup();
}

void ArturiaMiniLabUnit::setup() {
  // setup the SoundUnit
}

void ArturiaMiniLabUnit::processMidiMessage(int type, int key, float value) {
  // process incoming midi messages here
  switch(type) {
  case osc::MessageData::Types::MIDIOFF: {
    std::cout << "midi OFF message value=" << value  << ", KEY=" << key << std::endl;
    
    control("midi off", key);
    control("velocity", value);
    
    break;
  }
  case osc::MessageData::Types::MIDION: {
    std::cout << "midi ON message: value=" << value  << ", KEY =" << key << std::endl;

    control("midi on", key);
    control("velocity", value);    
    
    break;
  }
  }
}

void ArturiaMiniLabUnit::processControlMessage(int type, int key, float value) {
  // process incoming control messages here

  // Knobs ROW 1
  if (key == 7) { // volume
    control("volume", value);
  }   
  if (key == 74) { // cutoff
    control("cutoff", value);
  }
  if (key == 71) { // resonance
    control("resonance", value);
  }  
  if (key == 76) { // lfo rate
    control("lfo rate", value);
  }
  if (key == 77) { // lfo amnt
    control("lfo amnt", value);
  }
  if (key == 93) { // chorus amnt
    control("chorus amnt", value);
  }
  if (key == 73) { // attack
    control("attack", value);
  }
  if (key == 75) { // decay
    control("decay", value);
  }


  // Knobs ROW 2
  if (key == 114) { // preset
    control("preset", value);
  }
  if (key == 18) { // param 1
    control("param 1", value);
  }
  if (key == 19) { // param 2
    control("param 2", value);
  }
  if (key == 16) { // param 3
    control("param 3", value);
  }
  if (key == 17) { // param 4
    control("param 4", value);
  }
  if (key == 91) { // delay amnt
    control("delay amnt", value);
  }
  if (key == 79) { // sustain
    control("sustain", value);
  }
  if (key == 72) { // release
    control("release", value);
  }

  // Pads #9 - #16 (digital pads)
  if (key == 22) { // pad #9 (snapshot 1)
    control("pad 9", value);
  }
  if (key == 23) { // pad #10 (snapshot 2)
    control("pad 10", value);
  }
  if (key == 24) { // pad #11 (snapshot 3)
    control("pad 11", value);
  }
  if (key == 25) { // pad #12 (snapshot 4)
    control("pad 12", value);
  }
  if (key == 26) { // pad #13 (snapshot 5)
    control("pad 13", value);
  }
  if (key == 27) { // pad #14 (snapshot 6)
    control("pad 14", value);
  }
  if (key == 28) { // pad #15 (snapshot 7)
    control("pad 15", value);
  }
  if (key == 29) { // pad #16 (snapshot 8)
    control("pad 16", value);
  }

  // mod
  if (key == 1) { // mod slider
    control("mod", value);
  }
  
}

void ArturiaMiniLabUnit::control (std::string portName, float value) {
  // process the messages in your unit
}

float ArturiaMiniLabUnit::tick() {

  // HIER DER EIGENTLICHE AUDIO CODE
										  
  return 0.0 ;
}
