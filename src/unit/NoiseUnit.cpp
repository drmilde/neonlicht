#include "NoiseUnit.h"


NoiseUnit::NoiseUnit():SoundUnit("NoiseUnit 1") {
  setup();
}

void NoiseUnit::setup() {
  
  noise1 = new NoiseGen("Noise Generator 1");
  noise2 = new NoiseGen("Noise Generator 2");
  saw1 = new SawGen("Saw Generator 1");
  phasor1 = new PhasorGen("Phasor Generator 1");
  square1 = new SquareGen("Square Generator 1");
  eg1 = new EGUpDownGen("EG Up Down 1");
  onelpf = new OnePoleLPFGen("One Pole LPF");
  mixer1 = new TwoInputMixerGen("Two Input Mixer 1");
  mixer2 = new TwoInputMixerGen("Two Input Mixer 2");
  oneStepEG = new EGOneStepGen("One Step EG");
  oneStepEG->setDuration(2.0);
  oneStepEG->setStartLevel(1.0);
  oneStepEG->setEndLevel(.0);

  adsr1 = new ADSRGen("adsr 1");

  stkOneZero = new STKOneZeroGen();
  stkOneZero-> control ("amnt1", 0.0); // setting pole to -1.0

  stkTwoPole = new STKTwoPoleGen();
  stkTwoZero = new STKTwoZeroGen();
  stkBiQuad = new STKBiQuadGen();
  stkOnePole = new STKOnePoleGen();

  waveOut = new WaveOutGen();
  
  mixer1->control("amnt1", 0.5);
  mixer1->control("amnt2", 0.5);

  mixer2->control("amnt1", 1.0);
  mixer2->control("amnt2", 0.0);

  //onelpf->setPortValue("cutoff", 0.5);
  onelpf->setAmnt2(0.5); // amnt2 = cutoff
  
  addUGen(noise1);
  addUGen(noise2);
  addUGen(saw1);
  addUGen(square1);
  addUGen(eg1);
  addUGen(onelpf);
  addUGen(mixer1);
  addUGen(mixer2);
}

void NoiseUnit::control (std::string portName, float value) {
  if (portName == "cutoff") {
    onelpf->control("cutoff", value);
  }
  if (portName == "volume") {
    mixer2->control("amnt1", value);
    mixer2->control("amnt2", (1.0 - value)*0.1f);
  }
  if (portName == "lfo rate") {
    // calculate midi frequency
    float frequency = 440 * pow(2.0,((int)(value*127) - 69.0)/12.0);
    
    saw1->control("frequency", frequency * 1.012f);
    phasor1->control("frequency", frequency * 1.012f);
    square1->control("frequency", frequency);

    eg1->control("trigger", 1.0);
  }

  if (portName == "key") {
    // calculate midi frequency
    float frequency = 440 * pow(2.0,((int)(value) - 69.0)/12.0);
    saw1->control("frequency", frequency * 1.012f);
    square1->control("frequency", frequency);

    //eg1->control("trigger", 1.0);
  }

  
  if (portName == "eg duration") {
    // calculate midi frequency
    eg1->control("duration", value * 0.3f);
    eg1->control("trigger", 1.0);
  }

  // control the filters
  if (portName == "one pole zero") {
    // set zero on stk one pole filter
    stkOneZero->control("amnt1", value);
  }

  if (portName == "two pole resonance") {
    // set center frequency of two pole filter
    // 0 Hz to 1/2 of sampling frequency (e.g. 22050 Hz)
    stkTwoPole->control("amnt1", value);
    stkTwoZero->control("amnt1", value);
    stkBiQuad->control("amnt1", value);
    stkOnePole->control("amnt1", value);
  }

  if (portName == "two pole radius") {
    // set the radius of two pole filter
    // radius > 1, unstable filter
    stkTwoPole->control("amnt2", value);
    stkTwoZero->control("amnt2", value);
    stkBiQuad->control("amnt2", value);
  }

  if (portName == "filter type") {
    // set the filter type of BiQuad
    stkBiQuad->control("amnt3", value);
  }

  if (portName == "record on/off") { // switch recording on and off
    // set value to start/stop recording
    waveOut->control("amnt1", value);
  }

  if (portName == "trigger eg") {
    // trigger the eg
    oneStepEG->control("trigger", 1.0);
  }

  if (portName == "trigger adsr") {
    // trigger the adsr
    if (value > 0.5) {
      // send trigger an set gate to 1
      adsr1->control("trigger", 1);
      adsr1->control("gate", 1);
    } else {
      // set gate to 0
      adsr1->control("gate", 0);
    }
  }
}

float NoiseUnit::tick() {
  // be careful here, incorrect names lead to Segmentations Faults !!!!

  auto start = std::chrono::steady_clock::now();

  mixer1->setIn1(saw1->tick());
  mixer1->setIn2(square1->tick());
  //mixer1->setIn1(noise1->tick());
  //mixer1->setIn1(phasor1->tick());
  //mixer1->setIn1(oneStepEG->tick());
  
  //mixer1->setIn1(adsr1->tick());
  //mixer1->setAmnt1(adsr1->tick());
  
  //float eg1val = eg1->tick();
  //mixer1->setAmnt1(eg1val);
  //mixer1->setAmnt2(eg1val);
  
  //onelpf->setIn1(mixer1->tick());
  //mixer2->setIn1(onelpf->tick());
  
  //stkOneZero->setIn1(mixer1->tick());
  //mixer2->setIn1(stkOneZero->tick());

  //stkTwoPole->setIn1(mixer1->tick());
  //mixer2->setIn1(stkTwoPole->tick());
  
  //stkTwoZero->setIn1(mixer1->tick());
  //mixer2->setIn1(stkTwoZero->tick());

  //stkBiQuad->setIn1(mixer1->tick());
  //mixer2->setIn1(stkBiQuad->tick());

  //stkOnePole->setIn1(mixer1->tick());
  //mixer2->setIn1(stkOnePole->tick());

  waveOut->setIn1(mixer1->tick());
  mixer2->setIn1(waveOut->tick());
  

  //mixer2->setIn2(noise1->tick());
  //mixer2->setAmnt2(eg1val * 0.2);
  
  //mixer2->setIn2(noise1->tick());

  /*
  for (int i = 0; i < 1000; i++) {
  }
  */

  auto end = std::chrono::steady_clock::now();
  auto diff = end - start;
  long nanoS = std::chrono::duration_cast<std::chrono::nanoseconds>(diff).count();
  //std::cout << "nanos: " << nanoS << std::endl;
										
  
  return mixer2->tick() ;
  //return 0.0 ;
}
