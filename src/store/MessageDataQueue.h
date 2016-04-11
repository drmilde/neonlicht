#ifndef _MESSAGE_DATA_QUEUE_h_
#define _MESSAGE_DATA_QUEUE_h_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "GenericQueue.h"
#include "osc/MessageData.h"
#include <unistd.h>

class MessageDataQueue {
 private:
  GenericQueue<MessageData*> messageQueue;
 
 public:
  MessageDataQueue();
  void add(MessageData* m);
  MessageData* get();
  int size();
  void clear();
};

#endif

