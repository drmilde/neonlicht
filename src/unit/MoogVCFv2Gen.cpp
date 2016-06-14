#include "MoogVCFv2Gen.h"

using namespace unit;

MoogVCFv2Gen::MoogVCFv2Gen() : MoogVCFv2Gen("Robert 2") {
  // do something useful here
}

MoogVCFv2Gen::MoogVCFv2Gen(std::string name) : ResCutFilterGen(name) {
  update();
}

void MoogVCFv2Gen::control (std::string portName, float value) {
  ResCutFilterGen::control(portName, value); // process cutoff / resonance
  update();

  // add further controls here  
}

void MoogVCFv2Gen::update() {
  f = Interpolation::map(cutoff, 20.0, 22050.0, 0.0, 1.0) * 1.16;

  res *= 4; // to enable self oscillation
  fb = res * (1.0 - (0.15 * f * f)); // control feedback

  in1=in2=in3=in4=out1=out2=out3=out4=0;
}

// fast access functions 
void MoogVCFv2Gen::setCutoff(float v) {
  ResCutFilterGen::setCutoff(v);
  update();
}

void MoogVCFv2Gen::setResonance(float v) {
  ResCutFilterGen::setResonance(v);
  update();
}

// overrides tick() in UGen
float MoogVCFv2Gen::tick() {
  float input = getIn1() - (out4 * fb);
  input *= 0.35013 * (f*f)*(f*f);

  out1 = input + (0.3 * in1) + ((1 - f) * out1); // Pole 1
  in1  = input;
  out2 = out1 + (0.3 * in2) + ((1 - f) * out2);  // Pole 2
  in2  = out1;
  out3 = out2 + (0.3 * in3) + ((1 - f) * out3);  // Pole 3
  in3  = out2;
  out4 = out3 + (0.3 * in4) + ((1 - f) * out4);  // Pole 4
  in4  = out3;

  setOut1(out4);

  return getOut1();
}

