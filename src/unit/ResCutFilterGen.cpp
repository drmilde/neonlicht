#include "ResCutFilterGen.h"

using namespace unit;

ResCutFilterGen::ResCutFilterGen() : ResCutFilterGen("Generic Filter") {
  // do something useful here
}

ResCutFilterGen::ResCutFilterGen(std::string name) : UGen(name, 0) {
  // configure the filter here
}

void ResCutFilterGen::control (std::string portName, float value) {
  if (portName == "cutoff") {    
    setCutoff(Interpolation::map(value, 0.0, 1.0, 20.0, 22050.0));
  }

  if (portName == "resonance") {
    setResonance(value);    
  }
}

// fast access functions

void ResCutFilterGen::setCutoff(float v) {
  cutoff = v;
}

void ResCutFilterGen::setResonance(float v) {
  res = v;
}


// overrides tick() in UGen
float ResCutFilterGen::tick() {
  return 0;
}

