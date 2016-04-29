#ifndef _ENVELOPE_GEN_h_
#define _ENVELOPE_GEN_h_

#include <stdlib.h>
#include "UGen.h"

namespace unit {
  class EnvelopeGen : public UGen {

  public:
    EnvelopeGen();
    EnvelopeGen(std::string name);  
  };
}


#endif
