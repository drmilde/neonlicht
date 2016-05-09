#ifndef _PORT_h_
#define _PORT_h_

#include <string>
#include "PortType.h"
#include "IDGenerator.h"

class Port {

 public:
  Port();
  Port(std::string name, PortType t);

  std::string getName();
  std::string getID();
  PortType getType();
  float getValue();
  void setValue(float v);
  
 private:
  PortType type;
  float value;
  std::string NAME;

  // generate unique ID for Port
  std::string ID;
  static IDGenerator IDG;
};

#endif
