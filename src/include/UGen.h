#ifndef _U_GEN_h_
#define _U_GEN_h_

#include <string>
#include "Port.h"
#include "IDGenerator.h"

namespace unit {

/* {{{ */

/**
 * UGen is the base class for all Unit Generators.
 * It provides the underlying interface of the UGens.
 * Two methods have to be implemented by the UGens:
 * 
 * - void control(std::string portName, float value) is used to set port values 
 * of the UGen. The user has to dispatch the portName, no automatic dispatching
 * is available (due to performance issues!)
 * 
 * - float tick() is used to calculate the next output sample of the UGen.
 * Here the actual signal processing takes places. The user has to take care
 * of input and output of the UGen. 
 *
 * The default implementation of UGen provides three value ports 
 * (amnt1, amnt2, amnt3), two in ports (in1 and in2) and two out ports
 * (out1 and out2).
 * For these ports appropiate getter and setter methods are provided.
 * The user may implement more ports, if needed for the functionality
 * of the UGen.
 *
 * @author jtm
 * @since 04-2016
 * @version 1.0
 **/

/* }}} */

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

    //setter
    void setName(std::string name);

    // getter
    std::string getName();
    std::string getID();

    // should to be implemented/overridden by subclasses
    virtual void control(std::string portName, float value);  
    virtual float tick();

    // default ports getter/setter
    // fast acces functions
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
    void setIn3(float value);
    float getIn3();

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
    float in3;

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
