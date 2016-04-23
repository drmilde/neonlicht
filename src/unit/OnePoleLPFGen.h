#ifndef _ONE_POLE_LPF_GEN_h_
#define _ONE_POLE_LPF_GEN_h_


#include <stdlib.h>    
#include "UGen.h"

class OnePoleLPFGen: public UGen {

 public:
  OnePoleLPFGen();
  OnePoleLPFGen(std::string name);
  
  void control (std::string portName, float value);
  float tick(); // override standard implementation

 private:
  Port cutoffPort;
  Port lastPort;
  Port inPort;
  Port outPort;

  float cutoff;

  
};

#endif
