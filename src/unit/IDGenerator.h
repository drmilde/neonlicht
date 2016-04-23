#ifndef _ID_Generator_h_
#define _ID_Generator_h_

#include <string>
#include <iostream>


class IDGenerator {

 public:
  IDGenerator();
  std::string nextID();

 private:
  static int CURRENT_ID;
};

#endif
