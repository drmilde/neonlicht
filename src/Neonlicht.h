#ifndef _NEONLICHT_h
#define _NEONLICHT_h

#include <math.h>

#include "SineWave.h"
#include "RtAudio.h"
using namespace stk;

// Neonlicht includes
#include "store/CentralStore.h"
#include "configuration/ConfigurationManager.h"
#include "unit/NoiseGen.h"
#include "unit/NoiseUnit.h"

class Neonlicht {

 public:
  Neonlicht();
  ~Neonlicht();

  void configure();
  void start();
  void stop();

  // diagnostic function
  long getStreamLatency();

  // static stuff, callback and CentralStore (global State of the Engine)
  static int tick( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
	    double streamTime, RtAudioStreamStatus status, void *dataPointer );
  // data management and communication
  static CentralStore CS;
  static int CNT;

 private:
  void setup();

  // test tone generator
  SineWave sine;
  
  // for RTAudio
  RtAudio dac;
  RtAudio::StreamParameters parameters;
  RtAudioFormat format;
  unsigned int bufferFrames;
  ConfigurationManager* cfm;


};

#endif
