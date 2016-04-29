#ifndef _NEONLICHT_h
#define _NEONLICHT_h


/* {{{ main description*/

/** \mainpage Neonlicht documentation
 *
 * \section intro_sec Introduction
 *
 * Neonlicht is a synthesizer engine targeting the fast and easy
 * creation of SoundUnits (aka synthesizers and audio effects) that 
 * run on most Unix/Linux machines.
 *
 * More specifically Neonlicht is targeting the Raspberry 3 computer. 
 * As such it is optimized to be used with the low computing power
 * of this machine.
 *
 * I am aiming at using the engine as part of teaching students
 * in the field of digital media. As such, I am trying to design a
 * system, that is generally understandable, does not require to 
 * much of a prior knowledge in audio programming, but still offers
 * enough flexibilty and power to create interesting and expressive
 * musical instruments and audio effects. Using the Raspberry 3 is part
 * of this approach. I want the software to be running on cheap hardware
 * allowing students to experiment without the need of having access to
 * expensive fruity systems. 
 *
 * @author JTM, @email email: milde@hs-fulda.de
 * @date April 2016
 *
 * \section install_sec Installation
 * 
 * Installing Neonlicht on your computer is done by taking the usual steps.
 * The code is self contained, meaning all nessecary libraries are added
 * to the source distribution of Neonlicht.
 *
 * In order to compile Neonlicht you first compile the underlying libraries 
 * and, in a second step, compile Neonlicht and the additional tools.
 *
 * PLEASE NOTE: Part of this documentation is in German ... 
 * Sorry for the inconvenience. I am working on it :)
 * 
 *
 * \subsection step1 Step 1: Compiling the libraries
 *
 * to be done ...
 *
 */

/* }}} */

#include <math.h>
#include "RtAudio.h"

// Neonlicht includes
#include "store/CentralStore.h"
#include "configuration/ConfigurationManager.h"

// Unist to be used, testing only
#include "spu/NoiseUnit.h"
#include "spu/WorkshopSPU.h"

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

using namespace stk;

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
  
  // for RTAudio
  RtAudio dac;
  RtAudio::StreamParameters parameters;
  RtAudioFormat format;
  unsigned int bufferFrames;
  ConfigurationManager* cfm;


};

#endif
