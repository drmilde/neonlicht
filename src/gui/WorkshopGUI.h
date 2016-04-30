#ifndef _WORKSHOP_GUI_h_
#define _WORKSHOP_GUI_h_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <curses.h>

#include "GUI.h"

class WorkshopGUI : public GUI {

 public:
  WorkshopGUI();
  WorkshopGUI(std::string name);
  ~WorkshopGUI();

  void redraw();
  void setValue(std::string name, float value);
  
 private:
  void drawVCO(int x, int y, int fval, int wave, int pwmval);
  void drawVCF(int x, int y, int cuttoff, int res);
  void drawVCA(int x, int y, int mode);
  void drawVCOMod(int x, int y, int source, int amount, int dest);
  void drawVCFMod(int x, int y, int source, int amount, int polarity);
  void drawLFO(int x, int y, int rate, int wave);
  void drawEnvelope(int x, int y, int sustain, int attack, int decay);
  void drawGlideKnob(int x, int y, int glide);
  void drawInterface();
  
  WINDOW * mainwin, * vcoWin, * vcfWin, * vcaWin;
  WINDOW * vcoMod, * vcfMod;
  WINDOW * lfo, * envelope;
  WINDOW * glideKnob;


  char buffer [4];
  
  // internal value, defining status of GUI

  int freq;
  int wave;
  int pwm;
  int cutcoff;
  int res;
  int vcaMode;
  int vcoModSource;
  int vcoModAmount;
  int vcoModDest;
  int vcfModSource;
  int vcfModAmount;
  int vcfModPolarity;
  int lfoRate;
  int lfoWave;
  int sustain;
  int attack;
  int decay;
  int glide;

};
  

#endif
