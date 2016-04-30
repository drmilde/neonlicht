#ifndef _GUI_MAPPING_h_
#define _GUI_MAPPING_h_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

class GUIMapping {
 public:
  GUIMapping();

  static std::string mapMiniLab2Workshop (int key, int value);
};

#endif
