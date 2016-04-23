#include "OscActivator.h"


OscActivator::OscActivator() {
  // do something useful here
  oscOut = OscOutConnector("localhost", 7000);
  note = 50;
}

void OscActivator::callback(float value) {
  note = (note+1) % 2; // divider

  if (note == 0) {
    noteIdx = (noteIdx+1) % 16;
    std::cout << "sending note : " << noteIdx << std::endl;
    
    oscOut.sendMessage("/midi", 176, 76, littleMelody[noteIdx]-12, value);
  }
}

