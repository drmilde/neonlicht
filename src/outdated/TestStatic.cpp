#include "TestStatic.h"

void TestStatic::doSomething(int val) {
  store = val;
  TestStatic::md.setMessageData("a", 6,7,8, 1.2);
}

void TestStatic::printit() {
  std::cout << TestStatic::store << std::endl;

  std::string s = TestStatic::md.getMessage();
  std::cout << s << std::endl;
}

int TestStatic::store = 0;
MessageData TestStatic::md("/hallo", 1, 2, 3, 3.1415926);
