#include "PhasorGen.h"

using namespace unit;

PhasorGen::PhasorGen() : PhasorGen("set to stun") {
  //do something useful here 
}

PhasorGen::PhasorGen(std::string name) : SawGen("set to stun") {
  //do something useful here 
}


float PhasorGen::tick() {
  // calculate the values  

  setOut1((SawGen::tick()+1.0)/2.0);
  
  // return current tick() value
  return getOut1();
}

