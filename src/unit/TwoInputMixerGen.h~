#ifndef _TWO_INPUT_MIXER_GEN_h_
#define _TWO_INPUT_MIXER_GEN_h_


#include <iostream>    
#include <stdlib.h>    
#include "UGen.h"

class TwoInputMixerGen: public UGen {

 public:
  TwoInputMixerGen();
  TwoInputMixerGen(std::string name);
  
  float tick(); // override standard implementation
  void control(std::string portName, float value);

 private:
  Port amntPort1;
  Port amntPort2;
  Port inPort1;
  Port inPort2;
  Port outPort;
   
  
};

#endif
