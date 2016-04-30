#include "LFOWorkshopSPU.h"


LFOWorkshopSPU::LFOWorkshopSPU() : LFOWorkshopSPU("LFOWorkshopSPU") {
  // do something useful here
}

LFOWorkshopSPU::LFOWorkshopSPU(std::string name) : MultiOscillatorSPU(name) {
   // State/Interface of the SPU
}

void LFOWorkshopSPU::control(std::string portName, float value) {
  if (portName == "frequency") {
    MultiOscillatorSPU::control("frequency", value); 
  }
  if (portName == "select square") {
    MultiOscillatorSPU::control("select osc", 3);
  }
  if (portName == "select triangle") {
    MultiOscillatorSPU::control("select osc", 2);
  }
}


float LFOWorkshopSPU::tick() {
  return MultiOscillatorSPU::tick();
}
