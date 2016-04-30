#include "GUIMapping.h"

GUIMapping::GUIMapping() {
  // do something useful here
}

std::string GUIMapping::mapMiniLab2Workshop (int key, int value) {
  switch (key) {
  case 17: { // param4
    return "vcf mod amount";
    break;
  }
  case 19: { // param2
    return "pwm";
    break;
  }
  case 28: { // pad #15
    return "lfo wave triangle";
    break;
  }
  case 29: { // pad #16
    return "lfo wave square";
    break;
  }
  case 71: {
    return "resonance";
    break;
  }
  case 73: {
    return "attack";
    break;
  }
  case 74: {
    return "cutoff";
    break;
  }
  case 75: {
    return "decay";
    break;
  }
  case 76: {
    return "lfo rate";
    break;
  }
  case 77: { // lfo amt
    return "vco mod amount";
    break;
  }
  }
  return "unknown";
}


