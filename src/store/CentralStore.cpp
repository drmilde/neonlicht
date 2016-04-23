#include "CentralStore.h"


CentralStore::CentralStore() {
  // initalize data structures  
  midiQueue = MessageDataQueue();
  oscIn.talk = false; // do not write any messages to stdout
  std::thread lt1 = oscIn.startThread();
  
}

void CentralStore:: tick() {
  // do the update of the current state

  // has something fresh arrived on the midi Osc ?
  if (oscIn.isFresh()) {
    MessageData* data = oscIn.getData(); // get data
    
    if (data != NULL) { // don't copy empty data

      // check for midi data
      if (data->getMessage() == "/midi") {
	midiQueue.add(new MessageData(data)); // create new MessageData and put it into queue
      }

      // check for control data
      if (data->getMessage() == "/control") {
	controlQueue.add(new MessageData(data)); // create new MessageData and put it into queue
      }      
    }    
  }
}

void CentralStore::clear() {
  // clear the Central Store
  midiQueue.clear();
  controlQueue.clear();
}

MessageData* CentralStore::getMidiData() {
  MessageData* data = midiQueue.get();
  return (checkData(data));
}

MessageData* CentralStore::getControlData() {
  MessageData* data = controlQueue.get();
  return (checkData(data));
}


MessageData* CentralStore::checkData(MessageData* data) {
  if (data != NULL) {
    return data;
  }  else {
    return NULL;
  }  
}



