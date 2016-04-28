#include "OscillatorGen.h"

using namespace unit;

OscillatorGen::OscillatorGen() : OscillatorGen("The rise and fall of Jordan Belfort") {
}

OscillatorGen::OscillatorGen(std::string name) : UGen(name, 1) {
  // do something sensible here
}
