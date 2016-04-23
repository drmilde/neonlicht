#include "MessageData.h"

// constructor


MessageData::MessageData(MessageData* md): MessageData (md->getMessage(), md->getV1(), md->getV2(), md->getV3(),md->getF1()) {
  // create copy of that
}

MessageData::MessageData(std::string s, int a1, int a2, int a3, float f) {
  setMessageData(s, a1, a2, a3, f);
}


// GETTER

std::string MessageData::getMessage() {
  fresh = false;
  return message;
}

int MessageData::getV1() {
  fresh = false;
  return v1;
}

int MessageData::getV2() {
  fresh = false;
  return v2;
}

int MessageData::getV3() {
  fresh = false;
  return v3;
}

float MessageData::getF1() {
  fresh = false;
  return f1;
}

// SETTER


void MessageData::setMessageData (std::string s,
				  int a1, int a2, int a3,
				  float f) {
  setMessage(s);
  setV1(a1);
  setV2(a2);
  setV3(a3);
  setF1(f);
  
  fresh = true;
}

bool MessageData::isFresh() {
  return fresh;
}

void MessageData::setMessage(std::string s) {
  message = s;
}

void MessageData::setV1(int a1) {
  v1 = a1;
}


void MessageData::setV2(int a2) {
 v2 = a2;
}

void MessageData::setV3(int a3) {
  v3 = a3;
}

void MessageData::setF1(float f) {
  f1 = f;
}
