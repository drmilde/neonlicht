#include <iostream>

#include "unit/UGen.h"
#include "unit/NoiseGen.h"


int main()
{
  NoiseGen n("rand-Noise");
  NoiseGen n2("rand-Noise");

  std::cout << n.getName() << ", " << n.getID() << std::endl;
  std::cout << n2.getName() << ", " << n2.getID() << std::endl;

  for (int i = 0; i< 20; i++) {
    float v = n.tick();
    std::cout << "tick() is :" << v << ", " << n.getPortValue("out") << std::endl;
  }
    
  // Block waiting here.
  char keyhit;
  std::cout << "\nUGen ... press <enter> to quit.\n";
  std::cin.get( keyhit );

}
