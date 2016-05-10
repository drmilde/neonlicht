#ifndef _ENVELOPE_GEN_h_
#define _ENVELOPE_GEN_h_

#include <stdlib.h>
#include "UGen.h"

namespace unit {
  /**
   * EnvelopeGen is the common base class for all variations of envelope generators.
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class EnvelopeGen : public UGen {

  public:
    EnvelopeGen();
    EnvelopeGen(std::string name);  
  };
}


#endif
