#include "Neonlicht.h"

// redefine static variables, I still do not why ?
CentralStore Neonlicht::CS;
int Neonlicht::CNT = 0;

// global member (for testing purposes only)
//NoiseUnit nu1 = NoiseUnit();
MyUnit nu1 = MyUnit();

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

// This tick() function handles sample computation only.  It will be
// called automatically when the system needs a new buffer of audio
// samples.
int Neonlicht::tick( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double streamTime, RtAudioStreamStatus status, void *dataPointer )
{

  unit::SoundUnit *SU = (unit::SoundUnit *) dataPointer;

  
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
    osc::MessageData* midiMessage = CS.getMidiData();
    
    if (midiMessage != NULL) { // first the midi data
      
      int type = midiMessage->getType();
      int key = midiMessage->getKey();
      float value = midiMessage->getValue()/127.0; // norm value to [0,1]

      SU->processMidiMessage(type, key, value);
            
    } else {      
      osc::MessageData* controlMessage = CS.getControlData();

      if (controlMessage != NULL) { // now the control data
	
	int type = controlMessage->getType();
	int key = controlMessage->getKey();
        float value = controlMessage->getValue()/127.0; // norm value to [0,1]
	
	std::cout << "control message: ," << value  << ", KEY =" << key << std::endl;
	SU->processControlMessage(type, key, value);
      
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
  // configuration of the SoundUnit(s)
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

