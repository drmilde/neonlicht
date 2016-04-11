#include <cstdlib>
#include <cstring>
#include <iostream>

#include "osc/OscOutboundPacketStream.h"

#include "ip/UdpSocket.h"
#include "ip/IpEndpointName.h"

#define IP_MTU_SIZE 1536

class OscOutConnector {
  
 public:
  OscOutConnector();
  OscOutConnector(std::string h, int p);

  void sendMessage(std::string s, int a1, int a2, int a3, float f1 );

 private:
  void RunSendTests( const IpEndpointName& host, std::string s, int a1, int a2, int a3, float f1 );


  const char *hostName = "localhost";
  int port = 7000;
    
  IpEndpointName host;
  char hostIpAddress[ IpEndpointName::ADDRESS_STRING_LENGTH ];
};


