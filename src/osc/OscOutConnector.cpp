#include "OscOutConnector.h"

using namespace osc;

OscOutConnector::OscOutConnector() {
  OscOutConnector("localhost", 7000);
}

OscOutConnector::OscOutConnector(std::string h, int p): hostName(h.c_str()), port(p) {

  host = IpEndpointName( hostName, port);
  host.AddressAsString( hostIpAddress );  
}

void OscOutConnector::RunSendTests( const IpEndpointName& host, std::string s, int a1, int a2, int a3, float f1 )
{
  char buffer[IP_MTU_SIZE];
  osc::OutboundPacketStream p( buffer, IP_MTU_SIZE );
  UdpTransmitSocket socket( host );

  p.Clear();
  p << osc::BeginMessage( s.c_str() )
    << a1
    << a2
    << a3
    << f1
    << osc::EndMessage;
  socket.Send( p.Data(), p.Size() );
}


void OscOutConnector::sendMessage (std::string s, int a1, int a2, int a3, float f1) {
  OscOutConnector::RunSendTests (host, s, a1, a2, a3, f1);
}


