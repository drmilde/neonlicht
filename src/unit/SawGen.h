#ifndef _SAW_GEN_h_
#define _SAW_GEN_h_


#include <stdlib.h>    
#include "UGen.h"

class SawGen: public UGen {

 public:
  SawGen();
  SawGen(std::string name);
  
  void control(std::string portName, float value);  
  float tick(); // override standard implementation

 private:
  Port outPort;
  float stepy;
  float stepx;
  float currentx;
  float currenty;
  
  float frequency;
  
};

#endif
