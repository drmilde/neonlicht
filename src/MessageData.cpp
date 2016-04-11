#include "MessageData.h"

// constructor


MessageData::MessageData(MessageData* md): MessageData (md->getMessage(), md->getCode(), md->getKey(), md->getValue(),md->getF1()) {
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

int MessageData::getCode() {
  fresh = false;
  return code;
}

int MessageData::getKey() {
  fresh = false;
  return key;
}

int MessageData::getValue() {
  fresh = false;
  return value;
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
  setCode(a1);
  setKey(a2);
  setValue(a3);
  setF1(f);
  
  fresh = true;
}

bool MessageData::isFresh() {
  return fresh;
}

void MessageData::setMessage(std::string s) {
  message = s;
}

void MessageData::setCode(int a1) {
  code = a1;
}


void MessageData::setKey(int a2) {
 key = a2;
}

void MessageData::setValue(int a3) {
  value = a3;
}

void MessageData::setF1(float f) {
  f1 = f;
}
