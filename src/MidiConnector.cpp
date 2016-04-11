//*****************************************//
//
//  stepwise transformation into C++ class
//  JTM April, 2016
//
//*****************************************//

#include "MidiConnector.h"


OscOutConnector MidiConnector::oscCon("localhost", 7000);


MidiConnector::MidiConnector(int p):midiPort(p) {
  int result = setup(midiin);
  
  if (result == 0) {
    std::cout << "Unable to construct MidiConnector\n";
    std::cout << "trying to access midi at midiPort:" << midiPort << std::endl;

    // try again, asking user
    delete midiin;
    midiin = new RtMidiIn();
    chooseMidiPort(midiin);
    int result = setup(midiin);
  }
}

MidiConnector::MidiConnector():MidiConnector(1) {
}


MidiConnector::~MidiConnector() {
  delete midiin;
}


// Member functions

void MidiConnector::defaultCallback( double deltatime, std::vector< unsigned char > *message, void */*userData*/ )
{

  unsigned int nBytes = message->size();

  // Message Values
  int a1 = 0;
  int a2 = 0;
  int a3 = 0;
  float f1 = 0.0;

  if ((nBytes) > 0) {
    a1 = (int)message->at(0);
    f1 = (float) deltatime;
  }
  
  if ((nBytes) > 1)
    a2 = (int)message->at(1);

  if ((nBytes) > 2)
    a3 = (int)message->at(2);

  
  // dispatch and send to OSC
  std::string messageType = "/midi";
  
  switch (a2) {
  case 7: // volume
  case 74: // cutoff
  case 71: // resonance
  case 76: // lfo rate
  case 77: // lfo amnt
  case 93: // chorus amnt   
  case 75: // decay
  case 18: // param1
  case 19: // param2
  case 16: // param3
  case 17: // param4
  case 79: // sustain
  case 91: // delay amnt
  case 43: // pad #8
    {
    messageType = "/control";
    break;
  }
  }

  std::cout << messageType << ": code=" << a1 << ", key =" << a2 << ", value/velocity:" << a3 << std::endl;
  
  MidiConnector::oscCon.sendMessage(messageType, a1, a2, a3, f1);
}

// This function should be embedded in a try/catch block in case of
// an exception.  It offers the user a choice of MIDI ports to open.
// It returns false if there are no ports available.

bool MidiConnector::chooseMidiPort( RtMidiIn *rtmidi )
{
  std::cout << "\nWould you like to open a virtual input port? [y/N] ";

  std::string keyHit;
  std::getline( std::cin, keyHit );
  if ( keyHit == "y" ) {
    rtmidi->openVirtualPort();
    return true;
  }

  std::string portName;
  unsigned int i = 0, nPorts = rtmidi->getPortCount();
  if ( nPorts == 0 ) {
    std::cout << "No input ports available!" << std::endl;
    return false;
  }

  if ( nPorts == 1 ) {
    std::cout << "\nOpening " << rtmidi->getPortName() << std::endl;
    midiPort = 0;
  }
  else {
    for ( i=0; i<nPorts; i++ ) {
      portName = rtmidi->getPortName(i);
      std::cout << "  Input port #" << i << ": " << portName << '\n';
    }

    do {
      std::cout << "\nChoose a port number: ";
      std::cin >> i;
    } while ( i >= nPorts );
    std::getline( std::cin, keyHit );  // used to clear out stdin
    
    midiPort = i;
  }

  return true;
}


int MidiConnector::setup(RtMidiIn *midiin) {
  try {

    // RtMidiIn constructor
    midiin = new RtMidiIn();

    // Call function to select midiPort.
    //if ( chooseMidiPort( midiin ) == false ) return 0;
    midiin->openPort(midiPort);
    
    // Set our callback function.  This should be done immediately after
    // opening the port to avoid having incoming messages written to the
    // queue instead of sent to the callback function.
    //midiin->setCallback( &(MidiConnector::defaultCallback) );
    midiin->setCallback( &(this->defaultCallback) );

    // Don't ignore sysex, timing, or active sensing messages.
    midiin->ignoreTypes( false, false, false );


  } catch ( RtMidiError &error ) {
    error.printMessage();
    return 0;
  }

  return 1;
}  
