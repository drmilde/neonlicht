#ifndef _MIDI_INPUT_GEN_h_
#define _MIDI_INPUT_GEN_h_

#include <iostream>    
#include <stdlib.h>    
#include <algorithm>
#include "UGen.h"

namespace unit {
  /**
   * MidiInputGen processes the incoming midi messages and generates 
   * the gate and the trigger signals.
   *
   * Use a MidiInputGen as the first UGen in a SoundUnit in order to get the current status of
   * midi input. More specifically: use the gate and trigger value to control the sound
   * synthesis. 
   *
   * - **tick()** is providing the current **gate** value.
   * - the trigger is kept up (1.0) for exactly one tick() call.
   * - the gate is kept up (1.0) for as long as there are more **midi on** than **midi off**
   * events 
   * - the **gate** is stored in **out1**.
   * - the **trigger** is stored in **out2**.
   *
   * Control-Interface
   * 
   * - control("midi on", value) processes **midi on** event. **value** should hold the key.
   * - control("midi off", value) processes **midi off** event. **value** should hold the key.
   * - control("velocity", value) sets the **velocity** of the current key.
   * - control("reset", value) resets the counts, trigger is 0, gate is 0.
   *
   * Fast access functions
   *
   * - **getKey()**: returns the current key.
   * - **getVelocity()**: returns the current velocity.
   * - **getTrigger()**: returns the current trigger value.
   * - **getGate()**: returns the current gate value.
   *
   * @author jtm,
   * email: @email milde@hs-fulda.de
   * @since 04-2016
   * @version 1.0
   **/
  class MidiInputGen: public UGen {

  public:
    MidiInputGen();
    MidiInputGen(std::string name);
  
    float tick(); // override standard implementation
    void control(std::string portName, float value);

    // fast access functions
    float getKey();
    float getVelocity();
    float getGate();
    float getTrigger();

  private:
    int midiOnCount = 0;
    int triggerCount = 0;
     
  };
}

#endif
