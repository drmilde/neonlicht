#ifndef _ACTIVATOR_h_
#define _ACTIVATOR_h_

class Activator {

 public:
  Activator();

  // should be implemented/overridden by inherited class
  virtual void callback(float value);

};

#endif
