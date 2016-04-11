#ifndef _CENTRAL_STORE_h_
#define _CENTRAL_STORE_h_

#include "MessageDataQueue.h"
#include "osc/OscInConnector.h"
#include "TickData.h"

class CentralStore {

 public:
  CentralStore();
  void tick();
  void clear();
  MessageData* getMidiData();
  MessageData* getControlData();

  // storing current status
  TickData tickData;

 private:
  OscInConnector oscIn;
  MessageDataQueue midiQueue;
  MessageDataQueue controlQueue;

  MessageData* checkData(MessageData* data);
};

#endif
