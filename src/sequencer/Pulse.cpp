#include "Pulse.h"

// define static members
float Pulse::BPM;
bool Pulse::halt;
Activator* Pulse::AV = NULL;
float Pulse::ZWEIUNDDREISSIGSTEL;

Pulse::Pulse() {
  Pulse(120.0);
}

Pulse::Pulse(float bpm) {
  setSpeed(bpm);
  Pulse::halt = false;
  Pulse::AV = NULL;
  
  start();
}

void Pulse::setSpeed(float bpm) {
  Pulse::BPM = bpm;

  VIERTEL = (60.0f / Pulse::BPM) * 1000 * 10; // in tenth of a millisecond !!
  ACHTEL = VIERTEL / 2.0;
  SECHSZEHNTEL = ACHTEL / 2.0;
  ZWEIUNDDREISSIGSTEL = SECHSZEHNTEL / 2.0;

  HALBE = VIERTEL * 2;
  GANZE = HALBE * 2;
}

void Pulse::start() {
  std::thread LT(run);
  LT.detach();
}

void Pulse::stop() {
  Pulse::halt = true;
}


void Pulse::setActivator(Activator* a) {
  AV = a;
}



void Pulse::run() {
  long lastV = 0;
  
  auto start = get_time::now();
  
  while (!halt) {
    usleep(100/2);


    auto end = get_time::now();
    auto diff = end - start;
    long tenthOfMillis = std::chrono::duration_cast<ns>(diff).count() / 1000 / 100;

    int v = tenthOfMillis % (int)Pulse::ZWEIUNDDREISSIGSTEL;
    
    if (lastV > v) {
      // trigger the note playback
      if (Pulse::AV != NULL) {
	Pulse::AV->callback(tenthOfMillis/10000.0);
      }
    }
    lastV = v;
  }
}
