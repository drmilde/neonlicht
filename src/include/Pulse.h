#ifndef _PULSE_h_
#define _PULSE_h_

#include <iostream>
#include <thread>
#include <math.h>
#include <chrono>
#include <unistd.h>

#include "Activator.h"

using ns = std::chrono::nanoseconds;
using get_time = std::chrono::steady_clock;

/**
 * Pulse generates a beat and sends the pulses to an Activator.
 * The pulse is quantized to a zweiundreissigstel
 * (thirty second note/demisemiquaver).
 * 
 * 
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
class Pulse {

 public: 
  Pulse();
  Pulse(float bpm);

  void start();
  void stop();
  void setActivator(Activator* a);
  void setSpeed(float bpm);

 private:
  static void run();
  
  static float BPM;
  static bool halt;

  static Activator* AV;

  // note length in 1/10 of a millisecond
  float GANZE;
  float HALBE;
  float VIERTEL;
  float ACHTEL;
  float SECHSZEHNTEL;
  static float ZWEIUNDDREISSIGSTEL;
  
};

#endif
