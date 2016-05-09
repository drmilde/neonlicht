#ifndef _CENTRAL_STORE_h_
#define _CENTRAL_STORE_h_

#include "MessageDataQueue.h"
#include "OscInConnector.h"
#include "TickData.h"

class CentralStore {

 public:
  CentralStore();
  void tick();
  void clear();
  osc::MessageData* getMidiData();
  osc::MessageData* getControlData();

  // storing current status
  TickData tickData;

 private:
  osc::OscInConnector oscIn;
  MessageDataQueue midiQueue;
  MessageDataQueue controlQueue;

  osc::MessageData* checkData(osc::MessageData* data);
};

#endif
