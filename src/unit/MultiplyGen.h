#ifndef _MULTIPLY_GEN_h_
#define _MULTIPLY_GEN_h_

#include <stdlib.h>    
#include "UGen.h"

class MultiplyGen: public UGen {

 public:
  MultiplyGen();
  MultiplyGen(std::string name);
  
  void control(std::string portName, float value);  
  float tick(); // override standard implementation
  
};

#endif
