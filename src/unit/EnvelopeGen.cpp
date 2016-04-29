#include "EnvelopeGen.h"

using namespace unit;

EnvelopeGen::EnvelopeGen() : EnvelopeGen("Evgeniy Petrov") {
}

EnvelopeGen::EnvelopeGen(std::string name) : UGen(name,0) {
  // do something useful here
}
