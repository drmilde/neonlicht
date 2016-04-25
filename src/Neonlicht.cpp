#include "Neonlicht.h"


/**
 * 
 **/
Neonlicht::Neonlicht() {
  // default constructor
  setup();
}

Neonlicht::~Neonlicht() {
  // default destructor
}

// global member (for testing purposes only)
NoiseUnit nu1 = NoiseUnit();

// This tick() function handles sample computation only.  It will be
// called automatically when the system needs a new buffer of audio
// samples.
int Neonlicht::tick( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *dataPointer )
{

  SoundUnit *SU = (SoundUnit *) dataPointer;

  
  register StkFloat *samples = (StkFloat *) outputBuffer;  
  
  for ( unsigned int i=0; i<nBufferFrames; i++ ) {     
    *samples++ = SU->tick();
    //*samples++ = 0.0;
  }

  if (status == 1) {
    std::cout << "OVERFLOW" << std::endl;
  }

  if (status == 2) {
    std::cout << "UNDERFLOW" << std::endl;
  }

  // are there messages ?
  //CNT = (CNT + 1) % 10;
  CNT = 0;
  if (CNT == 0) {
    CS.tick();
    MessageData* midiMessage = CS.getMidiData();
    
    if (midiMessage != NULL) { // first the midi data
      
      int type = midiMessage->getType();
      float key = midiMessage->getKey();
      float value = midiMessage->getValue()/127.0;

      switch(type) {
      case MessageData::Types::MIDIOFF: {
	std::cout << "midi OFF message value=" << value  << ", KEY=" << key << std::endl;
	break;
      }
      case MessageData::Types::MIDION: {
	std::cout << "midi ON message: value=" << value  << ", KEY =" << key << std::endl;

	SU->control("key", key);

	break;
      }
      }
      
            
    } else {      
      MessageData* controlMessage = CS.getControlData();
      
      if (controlMessage != NULL) { // now the control data
	
	int type = midiMessage->getType();
	float key = controlMessage->getKey();
	float value = controlMessage->getValue()/127.0;
	
	std::cout << "control message: ," << value  << ", KEY =" << key << std::endl;
	
	if (key == 74) { // cutoff
	  SU->control("cutoff", value);
	}
	if (key == 7) { // volume
	  SU->control("volume", value);
	} 
	if (key == 71) { // resonance
	  SU->control("resonance", value);
	}
	if (key == 76) { // lfo rate
	  SU->control("lfo rate", value);
	}
	if (key == 18) { // param 1
	  SU->control("one pole zero", value);
	  SU->control("two pole zero", value);
	}
	if (key == 19) { // param 2
	  SU->control("two pole resonance", value);
	}
	if (key == 16) { // param 3
	  SU->control("two pole radius", value);
	}
	if (key == 17) { // param 4
	  SU->control("filter type", value);
	}
	if (key == 91) { // delay amt
	  SU->control("record on/off", value);
	}
	if (key == 43) { // pad #8, trigger EG
	  SU->control("trigger eg", value);
	}
	if (key == 79) { // sustain, test trigger ADSR
	  SU->control("trigger adsr", value);
	}
     }      
    }
  }

  return 0;
}


/// this routine is setting up Neonlicht
void Neonlicht::setup() {
  cfm = new ConfigurationManager();

  std::string path = cfm->getWorkingPath();
  std::cout << "You started Neonlicht from here :" << path << std::endl;
  
  cfm->load("configuration/neonlicht.cfg");
  
  // Set the global sample rate before creating class instances.
  Stk::setSampleRate( 44100.0 );

  // Figure out how many bytes in an StkFloat and setup the RtAudio stream.
  parameters.deviceId = dac.getDefaultOutputDevice();
  parameters.deviceId = 3;
  parameters.nChannels = 1;

  RtAudioFormat format = ( sizeof(StkFloat) == 8 ) ? RTAUDIO_FLOAT64 : RTAUDIO_FLOAT32;
  unsigned int bufferFrames = RT_BUFFER_SIZE/4;

  try {
    dac.openStream(
		   
		   // output stream parameters
		   &parameters,
		   // input stream parameters
		   NULL,
		   // RTAudio format
		   format,
		   // sample rate
		   (unsigned int)Stk::sampleRate(),
		   // desired size of audio buffer
		   &bufferFrames,
		   // callback routine, user defined
		   &tick,
		   // user data, that can be accessed in tick (e.g. oscillator)
		   //(void *)&sine 
		   (void *)&nu1 
		   // optionial pointer to gloabal stream option
		   // optional error callback
		   
		   );
  }
  catch ( RtAudioError &error ) {
    error.printMessage();
    //goto cleanup;
  }
}

void Neonlicht::start() {
  // start the main real time loop
  try {
    dac.startStream();
  }
  catch ( RtAudioError &error ) {
    error.printMessage();
    // goto cleanup;
    // MANAGE ERRORS properly ??
  }
}

void Neonlicht::stop() {
  // SYSTEM shutdown
  // Shut down the output stream.
  try {
    dac.closeStream();
  }
  catch ( RtAudioError &error ) {
    error.printMessage();
  }
}

void Neonlicht::configure() {
  // configuration of oscilator
  sine.setFrequency(440.0);
}


// diagnostic functions

long Neonlicht::getStreamLatency() {
  try {
    return dac.getStreamLatency();
  }
  catch ( RtAudioError &error ) {
    error.printMessage();
  }
  return -1;
}

// redefine static variables, I still do not why ?
CentralStore Neonlicht::CS;
int Neonlicht::CNT = 0;
