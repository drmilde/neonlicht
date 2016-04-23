#include <iostream>
#include <unistd.h>
#include <cstring>
#include <thread>
#include <mutex>

#include "OscInConnector.h"

int main(int argc, char* argv[])
{
  (void) argc; // suppress unused parameter warnings
  (void) argv; // suppress unused parameter warnings

  OscInConnector oscIn;

  std::thread lt = oscIn.startThread();

  while (true) {
    std::cout << "Schick doch mal was: " << oscIn.getData() << "\n" ;
    std::cout << "hiiiier kommt F -> " << oscIn.F << std::endl;
    sleep(1);
  }

  lt.join();

  return 0;
}

