#ifndef _MESSAGE_DATA_h_
#define _MESSAGE_DATA_h_

#include <iostream>

class MessageData {
 public:
  MessageData(std::string s, int a1, int a2, int a3, float f);
  MessageData(MessageData* md);
  std::string getMessage();
  int getV1();
  int getV2();
  int getV3();
  float getF1();

  void setMessage(std::string s);
  void setV1(int a1);
  void setV2(int a2);
  void setV3(int a3);
  void setF1(float f);

  void setMessageData(std::string s, int a1, int a2, int a3, float f);
  bool isFresh();

 private:
  std::string message;
  int v1;
  int v2;
  int v3;
  float f1;

  bool fresh;
};

#endif
