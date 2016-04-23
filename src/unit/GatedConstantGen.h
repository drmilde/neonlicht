#ifndef _GATED_CONSTANT_GEN_h_
#define _GATED_CONSTANT_GEN_h_

#include <stdlib.h>
#include "UGen.h"

class GatedConstantGen : public UGen {

 public:
  GatedConstantGen();
  GatedConstantGen(std::string name);

  void control(std::string portName, float value);
  float tick();

 private:
  bool isGated;
  
};


#endif
