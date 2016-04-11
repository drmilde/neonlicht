#include "WaveOutGen.h"

using namespace unit;

WaveOutGen::WaveOutGen() : WaveOutGen("Morton Rhue") {
}

WaveOutGen::WaveOutGen(std::string name) : UGen (name, 0) {
  // do something sensible here
  fname = "neonlicht-wave-out.wav";
}

void WaveOutGen::control(std::string portName, float value) {
  // no external control here
  if (portName == "amnt1") { // type := 1 => record, type := 0 => stop
    int type = Interpolation::discrete(value, 0.0, 1.0, 1);
    if (type == 1) {
      if (!isOpen) { // only open once !
	waveWriter.open(fname);
	doRecord = true;
	isOpen = true;
	isClosed = false;
      }
      std::cout << "recording is on ... type = " << type << std::endl;
    } else {
      doRecord = false;
      if (!isClosed) { // only open once
	waveWriter.close();
	isClosed = true;
	isOpen = false;
      }
      std::cout << "recording is off ... type = " << type << std::endl;
    }
  }
}


// overrides tick() in UGen
float WaveOutGen::tick() {
  // set input to ouput
  setOut1(getIn1());

  // store the current value in the wave file
  if (doRecord) {
    waveWriter.write(getIn1());
  }

  // return current tick() value
  return getOut1();
}


