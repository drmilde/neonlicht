#ifndef _OSC_IN_CONNECTOR_h_
#define _OSC_IN_CONNECTOR_h_

#include <iostream>
#include <cstring>
#include <thread>
#include <mutex>
#include <unistd.h>

// OSC to receive data
#include "osc/OscReceivedElements.h"
#include "osc/OscPacketListener.h"
#include "ip/UdpSocket.h"

#include "MessageData.h"

namespace osc {
  class OscInConnector {

  public:

    OscInConnector();
    OscInConnector(int prt);
  
    bool isFresh();
    MessageData* getData();
    std::thread startThread();
    MessageData* MD = new MessageData("xxx",1,2,3,3.14f);
    bool talk = true;

  public:
    class MidiPacketListener;
  
  private:
    static void listening();
    std::mutex oscMutex;
    bool fresh = false;

    int PORT;


  };
}

#endif
