#ifndef _PATCH_h_
#define _PATCH_h_

#include <string>

class Patch {

 public:
  Patch(std::string from, int ptFrom, std::string to, int pTo);

  std::string getFrom();
  int getFromPort();
  std::string getTo();
  int getFormPort();

 private:
  std::string FROM;
  int fromPort;
  std::string TO;
  int toPort;
 
};

#endif
