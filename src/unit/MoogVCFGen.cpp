#include "MoogVCFGen.h"

using namespace unit;

MoogVCFGen::MoogVCFGen() : MoogVCFGen("Robert") {
  // do something useful here
}

MoogVCFGen::MoogVCFGen(std::string name) : ResCutFilterGen(name) {
    cutoff = 440; // cutoff freq in Hz
    res = 0.5;    // resonance [0 - 1] (minimum - maximum)
    
    update();

    setOut1(0);
}

void MoogVCFGen::control (std::string portName, float value) {
  ResCutFilterGen::control(portName, value); // process cutoff / resonance
  update();
  // add further controls here
}

// fast access functions 
void MoogVCFGen::setCutoff(float v) {
  ResCutFilterGen::setCutoff(v);
  update();
}

void MoogVCFGen::setResonance(float v) {
  ResCutFilterGen::setResonance(v);
  update();
}


void MoogVCFGen::update() {
    fs = 44100.0; // sampling frequency //(e.g. 44100Hz)

    f = 2 * (cutoff / fs); // [0 - 1]
    k = (3.6 * f) - (1.6*f*f) - 1; //(Empirical tunning)
    p = (k+1)*0.5;

    scale = exp((1-p) * 1.386249);
    r = res*scale;
    
    y1=y2=y3=y4=oldx=oldy1=oldy2=oldy3=0;
}

// fast access functions are inherited

// overrides tick() in UGen
float MoogVCFGen::tick() {
  float x = getIn1() - r*y4;
  
  //Four cascaded onepole filters (bilinear transform)
  y1=x*p + oldx*p - k*y1;
  y2=y1*p+oldy1*p - k*y2;
  y3=y2*p+oldy2*p - k*y3;
  y4=y3*p+oldy3*p - k*y4;
  
  //Clipper band limited sigmoid
  y4 = y4 - (y4*y4*y4)/6;
  
  oldx = x;
  oldy1 = y1;
  oldy2 = y2;
  oldy3 = y3;

  setOut1(y4);

  return getOut1();
}

