#include "CosineGen.h"

using namespace unit;

CosineGen::CosineGen() : CosineGen("Everywhere I look something reminds me of her") {
  //do something useful here
}

CosineGen::CosineGen(std::string name) : SawGen(name) {
  //do something useful here 
  cosine = new CosineTable();
}


float CosineGen::tick() {
  // calculate the values
  // could as well use a phaoer here to provide the normed index

  setOut1(cosine->getNormedIdx(SawGen::tick()+1.0)/2.0);
  
  // return current tick() value
  return getOut1();
}

