#include "EGUpDownGen.h"


EGUpDownGen::EGUpDownGen() : EGUpDownGen("Tom Hanks") {
}

EGUpDownGen::EGUpDownGen(std::string name) : UGen(name, 3) {
  // add the ports
  durationPort = Port("duration", PortType::VALUE);  
  triggerPort = Port("trigger", PortType::VALUE);  
  outPort = Port("out", PortType::OUTPUT);

  addPort(durationPort);
  addPort(triggerPort);
  addPort(outPort);

  //setPortValue("duration", 0.1f);
  setAmnt1(0.1f); // amnt1 = duration
  //setPortValue("trigger", 0);
  setAmnt2(0.0f); // amnt2 = trigger 
  //setPortValue("out", 0);
  setOut1(0.0f);

  reset();
}

void EGUpDownGen::control (std::string portName, float value) {
  if (portName == "duration") {
    setAmnt1(value);
    reset();
  }
  if (portName == "trigger") {
    reset();
    setAmnt2(value);
  }
}

void EGUpDownGen::reset() {
  duration = getAmnt1();
  numberTicks = (int)(SAMPLING_FREQUENCY * duration);
  currentTick = 0;
  up = true;
  setAmnt2(0.0f); // amnt2 = trigger
}

// overrides tick() in UGen
float EGUpDownGen::tick() {
  // calculate the values
  // z = ((amnt1 * in1) + (amnt2 * in2));

  if (getAmnt2() > 0) { // amnt2 = trigger
    if (up) {
      float val = Interpolation::map (currentTick, 0, numberTicks, 0.0, 0.9);
      setOut1(val);

      currentTick++;
      up = (currentTick < numberTicks);
      
    } else {
      currentTick--;
      float val = Interpolation::map (currentTick, 0, numberTicks, 0.0, 0.9);
      setOut1(val);

      if (currentTick < 0) {
	reset();
      }
    }
  } else {
    setOut1(0.0); // not triggered ? then please be silent :)
  }

  // return current tick() value
  // usually the value of the out port
  return getOut1();
}

