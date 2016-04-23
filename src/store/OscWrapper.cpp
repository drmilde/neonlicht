#include "OscWrapper.h"


OscWrapper::OscWrapper() {
  oscIn.talk = false;
   // start listening
  std::thread lt = oscIn.startThread();
}
