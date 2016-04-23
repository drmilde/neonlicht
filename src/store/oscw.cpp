#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "OscWrapper.h"

int main(int argc, char** argv)
{
  std::cout << "Stuerzt das auch ab ?\n";
  OscWrapper oscw;

  /*
  OscInConnector oscIn;
  oscIn.talk = true;
  std::thread lt = oscIn.startThread();
  */

  
  for (int i = 0; i < 100; i++) {
    usleep(100 * 1000); // ein bischen warten
  }

  std::cout << std::endl;

  // ok, ready
  exit(0);
}
