//*****************************************//
//  Simple program to test MIDI input and
//  use of a user callback function.
//
//  stepwise transformation into C++ class
//  JTM April, 2016
//
//  based on cmidiin.cpp
//  by Gary Scavone, 2003-2004.
//
//*****************************************//

#include <iostream>
#include <cstdlib>
#include "osc/MidiConnector.h"

/// MAIN function

int main( int argc, char ** /*argv[]*/ )
{
  // start listening on midi port 1 (Arturia Minilab in my case)
  osc::MidiConnector mc1 = osc::MidiConnector(1);

  std::cout << "\nCLASS: Reading MIDI input ... press <enter> to quit.\n";
  char input;
  std::cin.get(input);
      
  return 0;
}

