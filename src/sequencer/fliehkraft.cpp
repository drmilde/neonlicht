#include <iostream>
#include "Pulse.h"
#include "OscActivator.h"

int main() {
  std::cout << "Fliehkraft Sequencer\n";

  Pulse thePulse = Pulse(120.0);
  OscActivator* oscA = new OscActivator();
  thePulse.setActivator(oscA);
  

  std::cout << "\nSequencing ... press <enter> to stop.\n";
  char input;
  std::cin.get(input);

  thePulse.stop();
  exit(0);
}
