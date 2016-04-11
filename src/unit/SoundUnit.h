#ifndef _SOUND_UNIT_h_
#define _SOUND_UNIT_h_

#include <map>
#include <string>

#include "UGen.h"

class SoundUnit {

 public:
  SoundUnit();
  SoundUnit(std::string name);

  void addUGen(unit::UGen* u);
  std::string getName();

  // abstract functions, must be implemented
  virtual void setup() = 0;
  virtual void control(std::string portName, float value) = 0;
  virtual float tick() = 0;

 protected:
  std::map<std::string, unit::UGen*> UGENS;

 private:
  std::string NAME;
};

#endif
