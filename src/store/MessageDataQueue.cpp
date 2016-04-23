#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include "MessageDataQueue.h"


MessageDataQueue::MessageDataQueue() {
  // initialisze GenericQueue
}

void MessageDataQueue::add (MessageData* m) {
  messageQueue.add(m);
}

MessageData* MessageDataQueue::get () {
  return messageQueue.remove();
}

int MessageDataQueue::size () {
  return messageQueue.size();
}

void MessageDataQueue::clear () {
  messageQueue.clear();
}
