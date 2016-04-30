#ifndef _MIDI_CONNECTOR_h_
#define _MIDI_CONNECTOR_h_

//*****************************************//
//  cmidiin.cpp
//  by Gary Scavone, 2003-2004.
//
//  Simple program to test MIDI input and
//  use of a user callback function.
//
//  stepwise transformation into C++ class
//  JTM April, 2016
//
//*****************************************//

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include "RtMidi.h"

// tranmitting to via osc
#include "util/KeyPressedControl.h"
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"
#include "gui/GUI.h"
#include "gui/WorkshopGUI.h"


#define ADDRESS "127.0.0.1"
#define PORT 7000
#define OUTPUT_BUFFER_SIZE 1024

// OSC Bridge
#include "OscOutConnector.h"
#include "gui/GUIMapping.h"


namespace osc {
  class MidiConnector {

  public:
    MidiConnector(int p);
    MidiConnector();
    ~MidiConnector();

    void sendMessage(std::string messageType, int code, int key, int value, float f1);
  
  private:
    static void defaultCallback( double deltatime, std::vector< unsigned char > *message, void */*userData*/ );
    int setup(RtMidiIn *midiin);
    bool chooseMidiPort( RtMidiIn *rtmidi );

    RtMidiIn *midiin = 0;
    int midiPort = 0;

    // Connector to OSC
    static OscOutConnector oscCon;
    static int KEYCOUNT;
    static util::KeyPressedControl keyControl;
    static GUI* gui;
  };
}

#endif
