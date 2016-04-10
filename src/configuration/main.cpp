//--------
// #include's
//--------

#include <locale.h>
#include <iostream>
#include <fstream>
#include <config4cpp/Configuration.h>
using namespace config4cpp;

int main() {

  //setlocale(LC_ALL, ""); // keine deutschen Zahlen !!!!

  std::string name;
  int portIn;
  int audioDevice;
  float version;

  const char *    scope = "neonlicht";
  Configuration * cfg = Configuration::create();

  try {

    cfg->parse("neonlicht.cfg");

    name   = cfg->lookupString(scope, "name");
    portIn = cfg->lookupInt(scope, "osc.port.in");
    audioDevice = cfg->lookupInt(scope, "audio.device");
    version = cfg->lookupFloat(scope, "version");

    std::cout << "Name = " << name << std::endl;
    std::cout << "Version = " << version << std::endl;
    std::cout << "Osc Port In = " << portIn << std::endl;
    std::cout << "Audio Device Number = " << audioDevice << std::endl;

    StringBuffer buf;
    cfg->dump(buf, false, scope, "");
    std::cout << buf.c_str() << std::endl;

    // write out to file
    std::ofstream out("output.txt");
    out << buf.c_str();
    out.close();

  } catch(const ConfigurationException & ex) {
    std::cout << ex.c_str() << std::endl;
  }

  cfg->destroy();
}


