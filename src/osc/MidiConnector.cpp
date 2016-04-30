//*****************************************//
//
//  stepwise transformation into C++ class
//  JTM April, 2016
//
//*****************************************//

#include "MidiConnector.h"

using namespace osc;

// static varables
OscOutConnector MidiConnector::oscCon("localhost", 7000);
int MidiConnector::KEYCOUNT = 0;
util::KeyPressedControl MidiConnector::keyControl;
GUI* MidiConnector::gui = new WorkshopGUI();


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
  delete gui;
  delete midiin;
}


// Member functions

void MidiConnector::defaultCallback( double deltatime, std::vector< unsigned char > *message, void */*userData*/ )
{

  unsigned int nBytes = message->size();

  // Message Values
  int code = 0;
  int key = 0;
  int value = 0;
  float f1 = 0.0;

  if ((nBytes) > 0) {
    code = (int)message->at(0);
    f1 = (float) deltatime;
  }
  
  if ((nBytes) > 1)
    key = (int)message->at(1);

  if ((nBytes) > 2)
    value = (int)message->at(2);

  
  // dispatch and send to OSC
  std::string messageType = "/unknown";
  
  // process code and set message type
  switch (code) {
  case 176: {
    messageType = "/control";
    break;
  }
  case 144: {
    messageType = "/midi on";
    break;
  }
  case 128: {
    messageType = "/midi off";
    break;
  }
  case 153: {
    messageType = "/pad on";
    break;
  }
  case 137: {
    messageType = "/pad off";
    break;
  }
  case 224: {
    messageType = "/slider";
    break;
  }
  }

  // display GUI/Message  
  if (gui != NULL) {
    if (messageType == "/control") {
      gui->setValue(GUIMapping::mapMiniLab2Workshop(key, value), value);
      gui->redraw();
    }
  } else {
    std::cout << messageType << " code=" << code;
    std::cout << ", key=" << key << ", value/velocity=" << value;
    std::cout << ", delta=" << f1 << "cnt = " << KEYCOUNT << std::endl;
  }

  usleep(5 * 1000); // ein bischen warten HACK HACK HACK -> die Queue funktioniert nicht richtig

  // this whole blcok seems to be completly meaningless ... nedd to work on it !!!

  // check for missing events
  if (messageType == "/midi on") {
    // only send midi on event if key has not been pressed -> only send midi on once
    if (!keyControl.isKeyPressed(key)) {
      keyControl.setKeyPressed(key);
      MidiConnector::oscCon.sendMessage(messageType, code, key, value, f1);
      KEYCOUNT++;
    }
  } else {
    if (messageType == "/midi off") {
      if (keyControl.isKeyPressed(key)) {
	// ok, there has been a pairing midi on event => send out midi off event
	MidiConnector::oscCon.sendMessage(messageType, code, key, value, f1);
	keyControl.clearKeyPressed(key);
	KEYCOUNT--;
      } else {
	// do not send midi off ! no matching midi on
      }
    } else {
      // any other message type send right away
      MidiConnector::oscCon.sendMessage(messageType, code, key, value, f1);
    }
  }
  // something is lost, more note off than note on,
  //clear everything and start all over --> 
  if (KEYCOUNT < 0) { 
    keyControl.clear();
    KEYCOUNT = 0;
  }
  
}

void MidiConnector::sendMessage(std::string messageType, int code, int key, int value, float f1) {
  MidiConnector::oscCon.sendMessage(messageType, code, key, value, f1);
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
