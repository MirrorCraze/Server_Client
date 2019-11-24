#include <iostream>
#include <fstream>
#include <WS2tcpip.h>
#include <ws2def.h>
#include <windef.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>

#ifndef SERVER_CLIENT_NEW_CLIENT_METHODS_H
#define SERVER_CLIENT_NEW_CLIENT_METHODS_H

#endif //SERVER_CLIENT_NEW_CLIENT_METHODS_H

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;

extern int initializeSocket(int &familyAddr, int &clientSock);
extern void initiateRequest(int clientSock, sockaddr_in &cliAddr);
extern sockaddr_in receiveIPAndPortNumber(int familyAddr);
extern void sendAndReceiveData(int clientSock);
extern void sendRequest(int clientSock, const string &fileName);
extern void receiveResponse(int clientSock, const string &fileName);
extern int initializeWinSock();
extern void closeConnection(int clientSock);