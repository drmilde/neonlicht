#include "WorkshopGUI.h"

WorkshopGUI::WorkshopGUI() : WorkshopGUI("Simply Beautiful") {
}

WorkshopGUI::WorkshopGUI(std::string name) {
  /*  Initialize ncurses  */

  if ( (mainwin = initscr()) == NULL ) {
    fprintf(stderr, "Error initialising ncurses.\n");
    exit(EXIT_FAILURE);
  }
 
  /*  Switch of echoing and disable keypad (for arrow keys)  */
  noecho();
  keypad(mainwin, FALSE);

  /*  Initialize colours  */
  start_color();                    

  /* redraw the interface */
  redraw();
}


WorkshopGUI::~WorkshopGUI() {
  // delete everything and refresh the screen

  /*  Clean up after ourselves  */
  delwin(glideKnob);
  delwin(envelope);
  delwin(lfo);
  delwin(vcfMod);
  delwin(vcoMod);
  delwin(vcaWin);
  delwin(vcfWin);
  delwin(vcoWin);
  delwin(mainwin);
  endwin();
  refresh();
}

// Interface Rountines

void WorkshopGUI::redraw() {
  drawInterface();
  refresh();
}

// mapping name to internal WorkshopGUI values
void WorkshopGUI::setValue(std::string name, float value) {
  if (name == "frequency") {
    freq = (int)value;
  }
  if (name == "wave") {
    wave = (int)value;
  }
  if (name == "pwm") {
    pwm = (int)value;
  }
  
  if (name == "cutoff") {
    cutcoff = (int)value;
  }
  if (name == "resonance") {
    res = (int)value;
  }
  
  if (name == "vca mode") {
    vcaMode = (int)value;
  }


  if (name == "vco mod source") {
    vcoModSource = (int)value;
  }
  if (name == "vco mod amount") {
    vcoModAmount = (int)value;
  }
  if (name == "vco mod destination") {
    vcoModDest = (int)value;
  }

  if (name == "vcf mod source") {
    vcfModSource = (int)value;
  }
  if (name == "vcf mod amount") {
    vcfModAmount = (int)value;
  }
  if (name == "vcf mod polarity") {
    vcfModPolarity = (int)value;
  }

  if (name == "lfo rate") {
    lfoRate = (int)value;
  }
  if (name == "lfo wave triangle") {
    lfoWave = 1;
  }
  if (name == "lfo wave square") {
    lfoWave = 0;
  }

  if (name == "sustain") {
    sustain = (int)value;
  }
  if (name == "attack") {
    attack = (int)value;
  }
  if (name == "decay") {
    decay = (int)value;
  }

  if (name == "glide") {
    glide = (int)value;
  }
}


// internal drawing routines
void WorkshopGUI::drawVCO(int x, int y, int fval, int wave, int pwmval) {
  vcoWin = subwin(mainwin, 7, 30, y, x);

  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(vcoWin, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    mvwaddstr(vcoWin, 1, 1, "VCO");
    
    sprintf(buffer,"%d ",fval);
    mvwaddstr(vcoWin, 3, 2, buffer);    
    mvwaddstr(vcoWin, 5, 2, "FREQ");
    
    mvwaddstr(vcoWin, 3, 15, "PULSE");
    mvwaddstr(vcoWin, 4, 15, "SAW");    
    mvwaddstr(vcoWin, 5, 12, "WAVE");
    if (wave == 0) {
      mvwaddstr(vcoWin, 3, 12, "*");
      mvwaddstr(vcoWin, 4, 12, " ");
    }
    if (wave == 1) {
      mvwaddstr(vcoWin, 4, 12, "*");
      mvwaddstr(vcoWin, 3, 12, " ");
    }

    sprintf(buffer,"%d ",pwmval);
    mvwaddstr(vcoWin, 3, 22, buffer);    
    mvwaddstr(vcoWin, 5, 22, "PWM");


    wbkgd(vcoWin,COLOR_PAIR(2));

  }
  wrefresh(vcoWin);  
}

void WorkshopGUI::drawVCF(int x, int y, int cuttoff, int res) {
  vcfWin = subwin(mainwin, 7, 18, y, x);


  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(vcfWin, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    mvwaddstr(vcfWin, 1, 1, "VCF");
    
    sprintf(buffer,"%d ",cuttoff);
    mvwaddstr(vcfWin, 3, 2, buffer);    
    mvwaddstr(vcfWin, 5, 2, "CUTOFF");

    sprintf(buffer,"%d ",res);
    mvwaddstr(vcfWin, 3, 12, buffer);    
    mvwaddstr(vcfWin, 5, 12, "RES");
    

    wbkgd(vcfWin,COLOR_PAIR(2));

  }
  wrefresh(vcfWin);  
}


void WorkshopGUI::drawVCA(int x, int y, int mode) {
  vcaWin = subwin(mainwin, 7, 10, y, x);


  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(vcaWin, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    mvwaddstr(vcaWin, 1, 1, "VCA");
    

    mvwaddstr(vcaWin, 3, 6, "ON");
    mvwaddstr(vcaWin, 4, 6, "EG");    
    mvwaddstr(vcaWin, 5, 2, "MODE");

    if (mode == 0) {
      mvwaddstr(vcaWin, 3, 3, "*");
      mvwaddstr(vcaWin, 4, 3, " ");
    }
    if (mode == 1) {
      mvwaddstr(vcaWin, 4, 3, "*");
      mvwaddstr(vcaWin, 3, 3, " ");
    }


    wbkgd(vcaWin,COLOR_PAIR(2));

  }
  wrefresh(vcaWin);  
}

void WorkshopGUI::drawVCOMod(int x, int y, int source, int amount, int dest) {
  vcoMod = subwin(mainwin, 7, 30, y, x);

  char buffer [33];

  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(vcoMod, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    mvwaddstr(vcoMod, 1, 1, "VCO MOD");


    mvwaddstr(vcoMod, 3, 5, "EG");
    mvwaddstr(vcoMod, 4, 5, "LFO");    
    mvwaddstr(vcoMod, 5, 2, "SOURCE");
    if (source == 0) {
      mvwaddstr(vcoMod, 3, 2, "*");
      mvwaddstr(vcoMod, 4, 2, " ");
    }
    if (source == 1) {
      mvwaddstr(vcoMod, 4, 2, "*");
      mvwaddstr(vcoMod, 3, 2, " ");
    }

    sprintf(buffer,"%d ",amount);
    mvwaddstr(vcoMod, 3, 12, buffer);    
    mvwaddstr(vcoMod, 5, 12, "AMOUNT");

    
    mvwaddstr(vcoMod, 3, 24, "PWM");
    mvwaddstr(vcoMod, 4, 24, "FREQ");    
    mvwaddstr(vcoMod, 5, 22, "DEST");
    if (dest == 0) {
      mvwaddstr(vcoMod, 3, 22, "*");
      mvwaddstr(vcoMod, 4, 22, " ");
    }
    if (dest == 1) {
      mvwaddstr(vcoMod, 4, 22, "*");
      mvwaddstr(vcoMod, 3, 22, " ");
    }

    wbkgd(vcoMod,COLOR_PAIR(2));

  }
  wrefresh(vcoMod);  
}

void WorkshopGUI::drawVCFMod(int x, int y, int source, int amount, int polarity) {
  vcfMod = subwin(mainwin, 7, 28, y, x);

  char buffer [33];

  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(vcfMod, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    mvwaddstr(vcfMod, 1, 1, "VCF MOD");


    mvwaddstr(vcfMod, 3, 5, "EG");
    mvwaddstr(vcfMod, 4, 5, "LFO");    
    mvwaddstr(vcfMod, 5, 2, "SOURCE");
    if (source == 0) {
      mvwaddstr(vcfMod, 3, 2, "*");
      mvwaddstr(vcfMod, 4, 2, " ");
    }
    if (source == 1) {
      mvwaddstr(vcfMod, 4, 2, "*");
      mvwaddstr(vcfMod, 3, 2, " ");
    }

    sprintf(buffer,"%d ",amount);
    mvwaddstr(vcfMod, 3, 12, buffer);    
    mvwaddstr(vcfMod, 5, 12, "AMOUNT");

    
    mvwaddstr(vcfMod, 3, 23, "[+]");
    mvwaddstr(vcfMod, 4, 23, "[-]");    
    mvwaddstr(vcfMod, 5, 19, "POLARITY");
    if (polarity == 0) {
      mvwaddstr(vcfMod, 3, 21, "*");
      mvwaddstr(vcfMod, 4, 21, " ");
    }
    if (polarity == 1) {
      mvwaddstr(vcfMod, 4, 21, "*");
      mvwaddstr(vcfMod, 3, 21, " ");
    }

    wbkgd(vcfMod,COLOR_PAIR(2));

  }
  wrefresh(vcfMod);  
}

void WorkshopGUI::drawLFO(int x, int y, int rate, int wave) {
  lfo = subwin(mainwin, 7, 30, y, x);

  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(lfo, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    mvwaddstr(lfo, 1, 1, "LFO");

    sprintf(buffer,"%d ",rate);
    mvwaddstr(lfo, 3, 2, buffer);    
    mvwaddstr(lfo, 5, 2, "RATE");

    
    mvwaddstr(lfo, 3, 20, "SQUARE");
    mvwaddstr(lfo, 4, 20, "TRIANGLE");    
    mvwaddstr(lfo, 5, 18, "WAVE");
    if (wave == 0) {
      mvwaddstr(lfo, 3, 18, "*");
      mvwaddstr(lfo, 4, 18, " ");
    }
    if (wave == 1) {
      mvwaddstr(lfo, 4, 18, "*");
      mvwaddstr(lfo, 3, 18, " ");
    }

    wbkgd(lfo,COLOR_PAIR(2));

  }
  wrefresh(lfo);  
}

void WorkshopGUI::drawEnvelope(int x, int y, int sustain, int attack, int decay) {
  envelope = subwin(mainwin, 7, 28, y, x);

  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(envelope, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    mvwaddstr(envelope, 1, 1, "ENVELOPE");


    mvwaddstr(envelope, 3, 5, "ON");
    mvwaddstr(envelope, 4, 5, "OFF");    
    mvwaddstr(envelope, 5, 2, "SUSTAIN");
    if (sustain == 0) {
      mvwaddstr(envelope, 3, 2, "*");
      mvwaddstr(envelope, 4, 2, " ");
    }
    if (sustain == 1) {
      mvwaddstr(envelope, 4, 2, "*");
      mvwaddstr(envelope, 3, 2, " ");
    }

    sprintf(buffer,"%d ",attack);
    mvwaddstr(envelope, 3, 12, buffer);    
    mvwaddstr(envelope, 5, 12, "ATTACK");

    sprintf(buffer,"%d ",decay);
    mvwaddstr(envelope, 3, 22, buffer);    
    mvwaddstr(envelope, 5, 22, "DECAY");
    
    wbkgd(envelope,COLOR_PAIR(2));

  }
  wrefresh(envelope);  
}


void WorkshopGUI::drawGlideKnob(int x, int y, int glide) {
  glideKnob = subwin(mainwin, 4, 9, y, x);

  if ( has_colors() && COLOR_PAIRS >= 2 ) {       
    box(glideKnob, 0, 0);
    
    init_pair(1,  COLOR_WHITE, COLOR_BLACK);
    init_pair(2,  COLOR_BLACK, COLOR_WHITE);

    sprintf(buffer,"%d",glide);
    mvwaddstr(glideKnob, 1, 2, buffer);    
    mvwaddstr(glideKnob, 2, 2, "GLIDE");

    wbkgd(glideKnob,COLOR_PAIR(2));

  }
  wrefresh(glideKnob);  
}


void WorkshopGUI::drawInterface() {

  mvaddstr(0, 2, "WORKSHOP-16  digital_synthesizer");

  drawVCO(2,1, freq, wave, pwm);
  drawVCF(31,1, cutcoff, res);
  drawVCA(49,1, vcaMode);
  
  drawVCOMod(2,7, vcoModSource, vcoModAmount, vcoModDest);
  drawVCFMod(31,7, vcfModSource, vcfModAmount, vcfModPolarity);

  drawGlideKnob(7,19, glide);

  drawLFO(2,13, lfoRate, lfoWave);
  drawEnvelope(31, 13, sustain, attack, decay);

  // draw keyboard
  mvaddstr(21, 25, "     *   *       *   *   *     ");
  mvaddstr(22, 25, "   *   *   *   *   *   *   *   *");


  // draw brand :)
  mvaddstr(0, 54, "m**de ");
}
