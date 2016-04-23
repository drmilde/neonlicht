#include "Neonlicht.h"

int main()
{
  Neonlicht dieKraftMaschine;
  
  //dieKraftMaschine.setup();
  dieKraftMaschine.configure();
  dieKraftMaschine.start();

    
  // Block waiting here.
  char keyhit;
  std::cout << "\nDie Kraftmaschine läuft und läuft und läuft ... press <enter> to quit.\n";
  std::cin.get( keyhit );

  dieKraftMaschine.stop();

 cleanup:
  return 0;
}
