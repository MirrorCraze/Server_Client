// CS3201 Computer Networks Project
// Semester B 2019/20
// By LIM Michael and DAWIEANG Phudis

#include <iostream>
#include <WS2tcpip.h>
#include <ws2def.h>
#include <stdlib.h>
#include "client_methods.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;

int main()
{
    // Step 0 : Initialize uses of WinSock.
    initializeWinSock();

    // Step 1 : Socket initialization
    int familyAddr;
    int clientSock;
    int status;
    try {
        status = initializeSocket(familyAddr, clientSock);
        if (status < 0) //fail to initialize
        {
            throw (WSAGetLastError());
        }
    }
    catch (int lastError)
    {
        cout << "Socket initialization failed. Error code: " << lastError;
        exit(-1);
    }

    // Step 2a :Receive IP and port number
    sockaddr_in cliAddr = receiveIPAndPortNumber(familyAddr);

    // Step 2b: Initiate connection request
    initiateRequest(clientSock, cliAddr);

    // Step 3 and 4. Send and receive data.
    sendAndReceiveData(clientSock);

    // Step 5: Close connection when input = "exit"
    closeConnection(clientSock);
    return 0;
}

