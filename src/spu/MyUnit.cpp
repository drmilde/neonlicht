#include "MyUnit.h"


MyUnit::MyUnit() : ArturiaMiniLabUnit("MyUnit") {
  // do something useful here

  pulse1 = new unit::PulseGen("pulse 1");
  waveOut = new unit::WaveOutGen("wave 1");
  frequency = new unit::NumberGen("frequency");

  lfo1 = new unit::CosineGen("osc 2");
  lfo1->control("frequency", 2.0);
  
}

void MyUnit::control(std::string portName, float value) {
  if (portName == "param 1") {
    frequency->control("frequency", value*440.0);
    pulse1->control("frequency", frequency->tick());
    std::cout << "f ... " << frequency->tick() << std::endl;
  }
  if (portName == "param 2") {
    pulse1->control("pwm", value);
  }
  if (portName == "param 3") {
    lfo1->control("frequency", value*10.0);
  }
  if (portName == "pad 15") {
    waveOut->control("record", 1);
  }
  if (portName == "pad 16") {
    waveOut->control("record", 0);
  }
}


float MyUnit::tick() {
  float lval = (lfo1->tick());
  
  //pulse1->setPulseWidth(lval);
  pulse1->setFrequency((frequency->tick()) * (1 + (lval * 0.1f)));
  return pulse1->tick();
}
