#include "ConfigurationManager.h"


ConfigurationManager::ConfigurationManager() {
  cfg = Configuration::create();
}

ConfigurationManager::~ConfigurationManager() {
  if (cfg != NULL) {
    cfg->destroy();
  }
}

std::string ConfigurationManager::getWorkingPath() {
  int MAXPATHLEN = 256;
  char temp[MAXPATHLEN];
  return ( getcwd(temp, MAXPATHLEN) ? std::string( temp ) : std::string("") );
}

void ConfigurationManager::load(std::string fname) {
  try {

    //setlocale(LC_ALL, ""); // keine deutschen Zahlen !!!!
    //cfg->parse("neonlicht.cfg");
    cfg->parse(fname.c_str());

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
}

