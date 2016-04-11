#ifndef _SOUND_UNIT_h_
#define _SOUND_UNIT_h_

#include <map>
#include <string>

#include "UGen.h"


namespace unit {
  /* {{{  class documentation */
/**
 *
 * SoundUnit is an abstract class defining the interface of the sound unit,
 * which represents the concept of a Sound Processing Unit (SPU).
 * This SPU could be the implementation of a virtual analog synthesizer,
 * a purely digital synthesizer, a digital audio effect or the brand new
 * never heard of sound device you have always dreamt of.
 *
 * SoundUnit is derived from unit::UGen, therfore implementations of SoundUnit
 * can be recursively combined to create more complex unit::SoundUnit(s) 
 * and unit::UGen(s). 
 *
 * In an SPU you would typically 
 * 
 * - combine a set of Unit Generators (unit::UGen),
 * - define the routing bewtween the UGens
 * - define input, output and control ports
 * - map the control message to these ports
 *
 * SPUs will be registered in Neonlicht and incoming Midi and Control
 * messages are then dispatched to the SPU.
 * The SPU is responsible for processing (or ignoring!) these messages.
 *
 * Anyway: the interface forces you to implement 5 methods:
 *
 * - setup() is where you configure and initialize your SPU.
 * 
 * - float tick() is where the actual sound processing takes place
 *
 * - processMidiMessage() is where you process the incoming midi data
 *
 * - processControlMessage() is where you process the incoming control data
 *
 * - control() is where you map messages to internal parameters of the SPU
 *
 * @author JTM
 * @since April, 2016
 *
 **/

/* }}} */

  class SoundUnit : public unit::UGen {

  public:
    SoundUnit();
    SoundUnit(std::string name);

    void addUGen(unit::UGen* u);
    std::string getName();

    // abstract functions, must be implemented
    virtual void setup() = 0;
    virtual float tick() = 0;

    virtual void processMidiMessage(int type, int key, float value) = 0;
    virtual void processControlMessage(int type, int key, float value) = 0;
    virtual void control(std::string portName, float value) = 0;

  protected:
    std::map<std::string, unit::UGen*> UGENS;

  private:
    std::string NAME;
  };
}

#endif
