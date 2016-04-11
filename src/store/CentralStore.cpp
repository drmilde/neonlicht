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
    osc::MessageData* data = oscIn.getData(); // get data
    
    if (data != NULL) { // don't copy empty data

      switch(data->getType()) {
      case osc::MessageData::Types::PADON:
      case osc::MessageData::Types::PADOFF:
      case osc::MessageData::Types::MIDION:
      case osc::MessageData::Types::MIDIOFF: {
	midiQueue.add(new osc::MessageData(data)); // create new MessageData and put it into midi queue
	break;
      }
      case osc::MessageData::Types::SLIDER: 
      case osc::MessageData::Types::CONTROL: {
	controlQueue.add(new osc::MessageData(data)); // create new MessageData and put it into control queue
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

osc::MessageData* CentralStore::getMidiData() {
  osc::MessageData* data = midiQueue.get();
  return (checkData(data));
}

osc::MessageData* CentralStore::getControlData() {
  osc::MessageData* data = controlQueue.get();
  return (checkData(data));
}


osc::MessageData* CentralStore::checkData(osc::MessageData* data) {
  if (data != NULL) {
    return data;
  }  else {
    return NULL;
  }  
}



