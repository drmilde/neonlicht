#ifndef _MESSAGE_DATA_QUEUE_h_
#define _MESSAGE_DATA_QUEUE_h_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "GenericQueue.h"
#include "MessageData.h"
#include <unistd.h>

class MessageDataQueue {
 private:
  GenericQueue<osc::MessageData*> messageQueue;
 
 public:
  MessageDataQueue();
  void add(osc::MessageData* m);
  osc::MessageData* get();
  int size();
  void clear();
};

#endif

