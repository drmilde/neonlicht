#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "CentralStore.h"

int main(int argc, char** argv)
{
  //OscInConnector* oscIn = new OscInConnector();
  //oscIn->talk = false;

  CentralStore CS;
  
  std::cout << "Test Central Store\n";

  // reading messages from connector an put it into queue
  for (int i = 0; i < 300; i++) {
    CS.tick();
    usleep(10 * 1000); // ein bischen warten
  }

  // read data from queue (50 messages)
  std::cout << "Jetzt das Auslesen\n";
  
  for (int i = 0; i < 50; i++) {
    MessageData* data = CS.getMidiData();
    if (data != NULL) {
      std::cout << data->getV3() << ",";
    }
    usleep(1 * 1000); // ein bischen warten
  }

  std::cout << std::endl;

  // ok, ready
  exit(0);
}
