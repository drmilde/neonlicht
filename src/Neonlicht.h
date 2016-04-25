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

/**
 * Neonlicht eine Synthesizer-Engine auf Basis des STK
 *
 * Die Engine lädt sogenannte SoundUnits (SoundUnit) und steuert diese
 * über die tick()-Methode.
 * Die SoundUnit generiert den aktuellen Sample, den
 * Neonlicht dann an das Audio-Subsystem weitergibt.
 * Neonlicht wird über OSC (OscInConnector) gesteuert. Die Engine verarbeitet 
 * dabei Midi-Messages (MessageData), die in OSC-Message mit festem Format
 * umgewandelt werden (müssen).   
 *
 * @author JTM, @email email: milde@hs-fulda.de
 * @date April 2016
 *
 **/
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
