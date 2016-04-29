#include "EGOneStepGen.h"

using namespace unit;

EGOneStepGen::EGOneStepGen() : EGOneStepGen("Madness") {
}

EGOneStepGen::EGOneStepGen(std::string name) : EnvelopeGen(name) {
  duration = 0.1;
  startLevel = 0.0;
  endLevel = 1.0;

  reset();
}

bool EGOneStepGen::finished() {
  return isReady;
}

void EGOneStepGen::setDuration (float seconds) {
  duration = seconds;
  reset();
}

void EGOneStepGen::setStartLevel (float level) {
  startLevel = level;
  reset();
}

void EGOneStepGen::setEndLevel (float level) {
  endLevel = level;
  reset();
}

void EGOneStepGen::reset() {
  samples = (int)(SAMPLING_FREQUENCY * duration);
  currentx = 0;
  isReady = false;
  hasStarted = false;
}

void EGOneStepGen::control (std::string portName, float value) {
  // external control to start the EG step
  // to be used inside more complex UGens

  if (portName == "trigger") {
    reset();
    hasStarted = true;
    std::cout << NAME << ": EG one step is triggered" << std::endl;
  }
}


// overrides tick() in UGen
float EGOneStepGen::tick() {
  // calculate the values
  setOut1(0.0);

  if ((hasStarted) && (!isReady)) {
    setOut1(Interpolation::map(currentx, 0, samples, startLevel, endLevel));
    currentx++;
    isReady = (currentx >= samples);
  }


  // return current tick() value
  return getOut1();
}

