#ifndef _CONFIGURATION_MANAGER_h_
#define _CONFIGURATION_MANAGER_h_

#include <locale.h>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <config4cpp/Configuration.h>
using namespace config4cpp;

class ConfigurationManager {

 public:
  ConfigurationManager();
  ~ConfigurationManager();

  void load(std::string fname);
  std::string getWorkingPath();
  
 private:
  std::string name;
  int portIn;
  int audioDevice;
  float version;

  const char *    scope = "neonlicht";
  Configuration* cfg;
  

};

#endif
