#ifndef _GUI_MAPPING_h_
#define _GUI_MAPPING_h_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

/**
 * GUIMapping maps the part of the Arturia Minilab 
 * key, knob, pad and slider codes to control strings
 * used in the ncurses version of the Workshop WorkshopGUI. 
 * 
 * @author jtm,
 * email: @email milde@hs-fulda.de
 * @since 04-2016
 * @version 1.0
 **/
class GUIMapping {
 public:
  GUIMapping();

  static std::string mapMiniLab2Workshop (int key, int value);
};

#endif
