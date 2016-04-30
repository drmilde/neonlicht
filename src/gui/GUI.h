#ifndef _GUI_h_
#define _GUI_h_


#include <string>
#include <iostream>

class GUI {
 public:
  GUI();
  virtual void setValue(std::string name , float value);
  virtual void redraw();
  
  
};

#endif

