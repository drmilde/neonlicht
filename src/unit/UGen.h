#ifndef _U_GEN_h_
#define _U_GEN_h_

#include <string>
#include "Port.h"
#include "util/IDGenerator.h"

namespace unit {

  class UGen {
  public:
    UGen();
    UGen(std::string name, int pn);
  
    void addPort(Port p);
    Port* getPorts();
    int getNumberOfPorts();
  
    float getPortValue(int pn);
    float getPortValue(std::string name);
  
    void setPortValue(int pn, float value);
    void setPortValue(std::string name, float value);
  
    int getPortIndex(std::string id);

    // getter
    std::string getName();
    std::string getID();

    // should to be implemented/overridden by subclasses
    virtual void control(std::string portName, float value);  
    virtual float tick();

    // default ports getter/setter
    void setAmnt1(float value);
    float getAmnt1();
    void setAmnt2(float value);
    float getAmnt2();
    void setAmnt3(float value);
    float getAmnt3();
  
    void setIn1(float value);
    float getIn1();
    void setIn2(float value);
    float getIn2();

    void setOut1(float value);
    float getOut1();
    void setOut2(float value);
    float getOut2();

  protected:
    float SAMPLING_FREQUENCY = 44100;

    // default ports values
    float amnt1;
    float amnt2;
    float amnt3;

    float in1;
    float in2;

    float out1;
    float out2;

    // ID
    std::string NAME;
    std::string ID;

  private:
    int numberPorts;
    int currentPort = 0;
    Port* ports;

    static IDGenerator IDG;

  
  };
}

#endif
