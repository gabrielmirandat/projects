#include <string>
#include<sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <UdpInterface.hpp>
#include <RoboCupGameControlData.h>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/thread/thread.hpp>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
  UdpInterface udpSend(GAMECONTROLLER_RETURN_PORT);
  UdpInterface udpGmCtrl (GAMECONTROLLER_DATA_PORT);
  RoboCupGameControlReturnData gmCtrl;
  RoboCupGameControlData gmCtrlData;

  struct sockaddr_in targetReceive;
  fd_set socks;
  FD_ZERO(&socks);
  FD_SET(udpGmCtrl.fd, &socks);
  int recvlen;
  socklen_t addrlen = sizeof(targetReceive);
  int nsocks = max(udpSend.fd, udpGmCtrl.fd) + 1;

  // Lendo arquivo de preferencias
  ifstream settings("settings.txt");
  string line;
  if(settings.is_open())
  {
    // Header
    getline(settings,line);
    // Version
    getline(settings,line);
    gmCtrl.version = atoi(line.c_str());
    // Team
    getline(settings,line);
    gmCtrl.team = atoi(line.c_str());
    // Player
    getline(settings,line);
    gmCtrl.player = atoi(line.c_str());
  }
  settings.close();
  cout << (int)gmCtrl.version << (int)gmCtrl.team << (int)gmCtrl.player << endl;
  while(true)
  {
    if (select(nsocks, &socks, NULL, NULL, NULL) >= 0) {
      if (FD_ISSET(udpGmCtrl.fd, &socks))
      {
        recvlen = udpGmCtrl.receive((char *)&gmCtrlData, sizeof(RoboCupGameControlData), (struct sockaddr *)&targetReceive, &addrlen);
        if(recvlen > 0)
        {
          printf("received %d bytes\n", recvlen);
          udpGmCtrl.send((char *)&gmCtrl, sizeof(gmCtrl), &targetReceive,GAMECONTROLLER_RETURN_PORT);
        }
      }
    }
  }

  return 0;
}
