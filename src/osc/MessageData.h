#ifndef _MESSAGE_DATA_h_
#define _MESSAGE_DATA_h_

#include <iostream>

class MessageData {

  
 public:
  enum Types {MIDION, MIDIOFF, CONTROL, PADON, PADOFF, SLIDER, UNKNOWN};

  
  MessageData(std::string s, int a1, int a2, int a3, float f);
  MessageData(MessageData* md);
  std::string getMessage();
  int getCode();
  int getKey();
  int getValue();
  float getF1();
  Types getType();

  void setMessage(std::string s);
  void adaptMessageType();
  void setCode(int a1);
  void setKey(int a2);
  void setValue(int a3);
  void setF1(float f);

  void setMessageData(std::string s, int a1, int a2, int a3, float f);
  bool isFresh();

 private:
  std::string message;
  int code;
  int key;
  int value;
  float f1;
  Types type;
  bool fresh;

  void setType(Types t);

};

#endif
