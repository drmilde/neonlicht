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

      switch(data->getType()) {
      case MessageData::Types::PADON:
      case MessageData::Types::PADOFF:
      case MessageData::Types::MIDION:
      case MessageData::Types::MIDIOFF: {
	midiQueue.add(new MessageData(data)); // create new MessageData and put it into midi queue
	break;
      }
      case MessageData::Types::SLIDER: 
      case MessageData::Types::CONTROL: {
	controlQueue.add(new MessageData(data)); // create new MessageData and put it into control queue
	break;
      }
      }

      delete(data); // free memory
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



