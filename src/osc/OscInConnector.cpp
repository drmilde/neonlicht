#include "OscInConnector.h"

using namespace osc;

class OscInConnector::MidiPacketListener : public osc::OscPacketListener {

private:
  OscInConnector * oscIn = 0;
  int PORT = 7000;

public:
  void setOscIn(OscInConnector * o) {
    oscIn = o;
  }

  int getPort() {
    return PORT++;
  }

protected:
  void writeData (std::string s, int a1, int a2, int a3, float f) {
    if (oscIn != 0) { // HACK, (mal wieder), Zugriff auf die globalen Variablen des Connectors
      oscIn->MD->setMessage(s);
      oscIn->MD->setCode(a1);
      oscIn->MD->setKey(a2);
      oscIn->MD->setValue(a3);
      oscIn->MD->setF1(f);
      oscIn->fresh = true;
    }
  }

  virtual void ProcessMessage( const osc::ReceivedMessage& m, 
			       const IpEndpointName& remoteEndpoint )
  {
    (void) remoteEndpoint; // suppress unused parameter warning
     
    try {
      // process midi message
      osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
      
      // 4 arguments expected
      int a1 = (arg++)->AsInt32();
      int a2 = (arg++)->AsInt32();
      int a3 = (arg++)->AsInt32();
      float f1 = (arg++)->AsFloat();
      
      // HACK, to check reaction
      if ((a1 == 153) && (a2 == 36)) { // first pad on Arturia MiniLab
	std::cout << "OK, bye bye, closing down" << std::endl;
	exit(0);
      }
      // HACK end
	 
      if( arg != m.ArgumentsEnd() )
	throw osc::ExcessArgumentException();
      

      // just send message, dont dispatch
      writeData (m.AddressPattern(), a1, a2, a3, f1);
      
    } catch( osc::Exception& e ){
      // any parsing errors such as unexpected argument types, or 
      // missing arguments get thrown as exceptions.
      std::cout << "error while parsing message: "
		<< m.AddressPattern() << ": " << e.what() << "\n";
    }
  }
};


// end of private class

OscInConnector::MidiPacketListener listener;

OscInConnector::OscInConnector():OscInConnector(7000) {
  // default port is set 7000
}

OscInConnector::OscInConnector(int prt) {
  PORT = prt;
}

bool OscInConnector::isFresh() {
  return fresh;
}

MessageData* OscInConnector::getData() {
  // get data
  oscMutex.lock();
  fresh = false;
  // MESSAGE DATA should be copied here !!!!!
  // free result after usage !! -> otherwise memory leak !
  MessageData* result = new MessageData(MD);
  oscMutex.unlock();
  
  return result;
}

void OscInConnector::listening() {
  int port = listener.getPort();
  
  UdpListeningReceiveSocket s(
			      IpEndpointName( IpEndpointName::ANY_ADDRESS, port),
			      &listener );
  
  std::cout << "OscIn start thread listening on port " << port << std::endl;
			      
  s.Run();
}

std::thread OscInConnector::startThread() {
  listener.setOscIn(this);
  std::thread lt{listening};
  
  lt.detach(); /// Scheint zu funktionieren, keine Ahnung warum :)
  return lt;
}
