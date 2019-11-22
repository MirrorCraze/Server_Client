// CS3201 Computer Networks Project
// Semester B 2019/20
// By LIM Michael and DAWIEANG Phudis

#include <iostream>
#include <fstream>
#include <cstdio>
#include <WS2tcpip.h>
#include <ws2def.h>
#include <windef.h>
#include <string>
#include <cstring>
#include <stdlib.h>


#define FILE_SIZE 500
#define BUFFER_SIZE 1024
#define MAX_TRIES 10
#define CHUNK_SIZE 512

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;

// Method definition
int initializeSocket(int &familyAddr, int &clientSock);
void initiateRequest(int clientSock, sockaddr_in &cliAddr);
sockaddr_in receiveIPAndPortNumber(int familyAddr);
void sendAndReceiveData(int clientSock);
void sendRequest(int clientSock, const string &fileName);
void receiveResponse(int clientSock, const string &fileName);
int main()
{
    //Step 0 : Initialize uses of WinSock.
    WSADATA wsaData;
    int err = WSAStartup(MAKEWORD(2, 2), &wsaData);

    //Step 1 : Socket initialization
    int familyAddr;
    int clientSock;
    int status;
    try{
        status = initializeSocket(familyAddr, clientSock);
        if(status < 0) //fail to initialize
        {
            throw (WSAGetLastError());
        }
    }
    catch(int lastError)
    {
        cout << "Socket initialization failed. Error code: " << lastError;
        return -1;
    }

    //Step 2a :Receive IP and port number
    sockaddr_in cliAddr = receiveIPAndPortNumber(familyAddr);

    //Step 2b: Initiate connection request
    initiateRequest(clientSock, cliAddr);

    //Step 3 and 4. Send and receive data.
    sendAndReceiveData(clientSock);

    //Step 5: Close connection when input = "exit"
    closesocket(clientSock); //Close connection.
    cout << "Connection closed.\n";
    return 0;
}
int initializeSocket(int &familyAddr, int &clientSock) {
    familyAddr= AF_INET; //Address family IPv4
    clientSock= socket(familyAddr, SOCK_STREAM, 0); // Create new socket
    return clientSock;
}
sockaddr_in receiveIPAndPortNumber(int familyAddr) {
    cout << "Input the IP Address:";
    string serverIpAddr;
    cin >> serverIpAddr;
    int portNumber; //Port number
    cout << "Port number: ";
    cin >> portNumber;
    struct sockaddr_in cliAddr;
    //initialize transport address
    cliAddr.sin_family = familyAddr;
    cliAddr.sin_port = htons(portNumber);
    int convertStatus;
    try{
        convertStatus = inet_pton(familyAddr, serverIpAddr.c_str(), &cliAddr.sin_addr); //Copy IP as a string(serverIpAddr) and add address to cliAddr
        if(convertStatus <= 0)
            throw convertStatus;
    }
    catch(int errorCode)
    {
        if(errorCode == 0)
            printf("\nInvalid address/Address not supported\n");
        else //familyAddr is wrong.
            printf("\nWrong address family \n");
        exit(EXIT_FAILURE);
    }
    return cliAddr;
}
void initiateRequest(int clientSock, sockaddr_in &cliAddr) {
    int connectStat = -1; // Not connect yet.
    int connectTries = 0; //Amount of time socket tried to connect.
    while(connectStat != 0 && connectTries < MAX_TRIES) //While connection is not successful (0 == success) and connection tries not more than 10.
    {
        try{
            connectStat = connect(clientSock, (sockaddr*) &cliAddr, sizeof(cliAddr));
            connectTries++;
            printf("\nConnection status: ");
            if(connectStat == SOCKET_ERROR) //connect return 0 if success
                throw WSAGetLastError();

        }
        catch (int error_code) {
            if (error_code == WSAETIMEDOUT)
                cout << "Connection timed out.\n";
            else if (error_code == WSAECONNREFUSED)
                cout << "Connection refused.\n";
            cout << "Try again. Amount of tries: " << connectTries;
        }
    }
    if(connectTries == MAX_TRIES) // Connection tries limit reached.
    {
        cout << "\nConnection limit reached. Closing program...";
        exit(EXIT_FAILURE);
    }
    printf("Success!\n");
}
void sendRequest(int clientSock, const string &fileName) {
    int sentBytes = 0;
    int bytesInBuffer = NULL;
    char *fileNameBuffer = NULL;
    int fileNameLength = fileName.size();
    fileNameBuffer = new char[fileNameLength+1];
    strncpy(fileNameBuffer, fileName.c_str(), fileNameLength);
    cout << "\nSend status: ";
    do {
        bytesInBuffer = send(clientSock, fileNameBuffer, fileNameLength, 0);
        if (bytesInBuffer < 0) {
            cout << "fail";
//            printf("error: %s (error code: %d)", strerror(errno), errno);
        } else {
            sentBytes += bytesInBuffer;
        }
    } while (sentBytes < 0);
    cout << "success";
    delete fileNameBuffer;
}
void receiveResponse(int clientSock, const string &fileName) {// Before Step 4: Initialize file
    cout << "\nOpen file status: ";
    ofstream outFile;
    outFile.open(fileName, ofstream::out);
    outFile.good() ? cout << "success" : cout << "fail";
    // Step 4a: Receive content
    char *recvBuffer;
    char *receivedMessage = NULL;
    int recvBytes = 0;
    recvBuffer = new char[CHUNK_SIZE];

    cout << "\nReceived text: ";
    recvBytes = recv(clientSock, recvBuffer, CHUNK_SIZE, 0);
    if (recvBytes < 0) {
        cout << "\nError receiving message!\n";
    }
    string save_status = "success";
    while(recvBytes > 0)
    {
        int receivedMessageLength = recvBytes;
        receivedMessage = new char[receivedMessageLength+1];
        strncpy(receivedMessage, recvBuffer, receivedMessageLength);
        *std::find(receivedMessage, receivedMessage + receivedMessageLength,'\0') = '\0'; //End string.
        cout << receivedMessage << endl;
        // Save to text file

        for (int i = 0; i < receivedMessageLength; ++i) {
            if (outFile.good()) {
                outFile << receivedMessage[i];
            } else {
                save_status = "error";
            }
        }
        if(recvBytes < CHUNK_SIZE)
            break;
        recvBytes = recv(clientSock, recvBuffer, CHUNK_SIZE, 0);

    }
    cout << "Save text status: ";
    cout << save_status;
    delete receivedMessage;
    delete recvBuffer;
    outFile.close();
    cout << endl;
}

void sendAndReceiveData(int clientSock) {
    string fileName;
    cin.ignore(); // Ignore newline from previous input

    while (1) {
        //Step 3: Send request to file server
        cout << "Input the file name to be requested from the server:" << endl;
        // Get as string and convert to C string for buffer
        getline(cin, fileName);
        if (fileName.compare("exit") == 0) break;
        sendRequest(clientSock, fileName);
        //Step 4: Receive content and save to a file
        receiveResponse(clientSock, fileName);
    }
}




