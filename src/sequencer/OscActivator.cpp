#include "OscActivator.h"


OscActivator::OscActivator() {
  // do something useful here
  oscOut = osc::OscOutConnector("localhost", 7000);
  note = 50;
}

void OscActivator::callback(float value) {
  note = (note+1) % 2; // divider

  if (note == 0) {
    noteIdx = (noteIdx+1) % 16;
    std::cout << "sending note : " << noteIdx << std::endl;

    // release previous note
    oscOut.sendMessage("/midi off", 128, littleMelody[(noteIdx-1)%16]-12, 0,  value);
    // press current note 
    oscOut.sendMessage("/midi on", 144, littleMelody[noteIdx]-12, 64, value);
  }
}

