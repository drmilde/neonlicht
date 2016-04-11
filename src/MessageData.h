#ifndef _MESSAGE_DATA_h_
#define _MESSAGE_DATA_h_

#include <iostream>

class MessageData {
 public:
  MessageData(std::string s, int a1, int a2, int a3, float f);
  MessageData(MessageData* md);
  std::string getMessage();
  int getCode();
  int getKey();
  int getValue();
  float getF1();

  void setMessage(std::string s);
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

  bool fresh;
};

#endif
