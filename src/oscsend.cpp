#include "OscOutConnector.h"

/// hier komt MAIN

int main(int argc, char* argv[])
{
  OscOutConnector ooc = OscOutConnector("localhost", 7000);
  

  for (int i = 0; i < 5; i++) {
    ooc.sendMessage("/mymessage", i, i*2, 3, (float)2.71 );
  }
}

