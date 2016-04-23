#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "MessageDataQueue.h"
#include "OscInConnector.h"

int main(int argc, char** argv)
{
  // Create the queue and a input connector listening on standard port
  MessageDataQueue md = MessageDataQueue();
  OscInConnector oscIn;
  oscIn.talk = false;
  
 
  // Add items to the queue
  MessageData* data;
  

  // start listening
  std::thread lt = oscIn.startThread();

  // reading messages from connector an put it into queue
  for (int i = 0; i < 300; i++) {
    if (oscIn.isFresh()) {
      data = oscIn.getData(); // get data
      if (data != NULL) { // dont copy empty data
	md.add(new MessageData(data)); // create nwe MessageData and put it into queue
	std::cout << data->getV3() << ",";
      }
    }
    usleep(10 * 1000); // ein bischen warten
  }

  std::cout << std::endl;

  // read data from queue (50 messages)
  std::cout << "Jetzt das Auslesen\n";
  
  for (int i = 0; i < 50; i++) {
    data = md.get();
    if (data != NULL) {
      std::cout << data->getV3() << ",";
    }
    usleep(1 * 1000); // ein bischen warten
  }

  std::cout << std::endl;

  // ok, ready
  exit(0);
}
