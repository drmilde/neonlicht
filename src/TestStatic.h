#include <iostream>
#include "MessageData.h"

class TestStatic {
 public:
  static void doSomething(int val);
  void printit();

 private:
  static  int store;
  static  MessageData md;
};
