#ifndef _MIDI_CONNECTOR_h_
#define _MIDI_CONNECTOR_h_

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include "RtMidi.h"

// tranmitting to via osc
#include "KeyPressedControl.h"
#include "osc/OscOutboundPacketStream.h"
#include "ip/UdpSocket.h"
#include "GUI.h"
#include "WorkshopGUI.h"


#define ADDRESS "127.0.0.1"
#define PORT 7000
#define OUTPUT_BUFFER_SIZE 1024

// OSC Bridge
#include "OscOutConnector.h"
#include "GUIMapping.h"


namespace osc {
  /**
   * MidiConnector tries to connect to a given port number and reads the incoming 
   * midi messages from a connected USB midi device.
   *
   * The port number depends onto the current hardware configuration of your system. 
   *
   * All incoming midi messages are processed, categorized and 
   * transmitted as OSC-messages.
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
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
