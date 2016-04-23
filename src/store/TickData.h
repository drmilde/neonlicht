#ifndef _TICK_DATA_h_
#define _TICK_DATA_h_

#include "utilities.h"

struct TickData {
  stk::StkFloat volume;
  stk::StkFloat t60;
  unsigned int nWvOuts;
  int nVoices;
  int currentVoice;
  int channels;
  int counter;
  bool realtime;
  bool settling;
  bool haveMessage;
  int frequency;
  
  // Default constructor.
TickData()
: volume(1.0), t60(0.75),
    nWvOuts(0), nVoices(1), currentVoice(0), channels(2), counter(0),
    realtime( false ), settling( false ), haveMessage( false ) {}
};

#endif
