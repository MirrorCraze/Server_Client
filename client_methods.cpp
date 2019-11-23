//
// Created by Michael on 23/11/2019.
//

#include "client_methods.h"

#define MAX_TRIES 10
#define CHUNK_SIZE 512


void initializeWinSock() {
    WSADATA wsaData;
    int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
}
int initializeSocket(int &familyAddr, int &clientSock) {
    familyAddr= AF_INET; //Address family IPv4
    clientSock= socket(familyAddr, SOCK_STREAM, 0); // Create new socket
    return clientSock;
}
sockaddr_in receiveIPAndPortNumber(int familyAddr) {
    cout << "Input the IP Address: " << endl;
    string serverIpAddr;
    cin >> serverIpAddr;
    int portNumber = 12345; //Port number

    cout << "IP Address: " << serverIpAddr << '\t' << '\t' << "Port Number: " << portNumber;
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
            cout << endl << "Error - Invalid address or address not supported" << endl;
        else //familyAddr is wrong.
            cout << endl << "Error - Wrong address family" << endl;
        cout << endl;
        return receiveIPAndPortNumber(familyAddr);
    }
    return cliAddr;
}
void initiateRequest(int clientSock, sockaddr_in &cliAddr) {
    int connectStat = -1; // Not connect yet.
    int connectTries = 0; //Amount of time socket tried to connect.
    while(connectStat != 0 && connectTries < MAX_TRIES) //While connection is not successful (0 == success) and connection tries not more than 10.
    {
        try {
            connectStat = connect(clientSock, (sockaddr*) &cliAddr, sizeof(cliAddr));
            connectTries++;
            cout << endl << "Connection status: ";
            if(connectStat == SOCKET_ERROR) //connect return 0 if success
                throw WSAGetLastError();
        }
        catch (int error_code) {
            if (error_code == WSAETIMEDOUT)
                cout << "Connection timed out." << endl;
            else if (error_code == WSAECONNREFUSED)
                cout << "Connection refused." << endl;
            cout << "Try again. Amount of tries: " << connectTries;
        }
    }
    if(connectTries == MAX_TRIES) // Connection tries limit reached.
    {
        cout << endl << "Connection limit reached. Closing program...";
        exit(EXIT_FAILURE);
    }
    cout << "success" << endl;
}
void sendRequest(int clientSock, const string &fileName) {
    int sentBytes = 0;
    int bytesInBuffer = NULL;
    char *fileNameBuffer = NULL;
    int fileNameLength = fileName.size();
    fileNameBuffer = new char[fileNameLength+1];
    *std::find(fileNameBuffer, fileNameBuffer + fileNameLength,'\0') = '\0'; //End string.
    strncpy(fileNameBuffer, fileName.c_str(), fileNameLength);
    cout << endl << "Send status: ";
    try {
        do {
            bytesInBuffer = send(clientSock, fileNameBuffer, fileNameLength + 1, 0);
            if (bytesInBuffer < 0) {
                throw std::runtime_error("error, cannot send message");
            }
            sentBytes += bytesInBuffer;
        } while (sentBytes < 0);
        cout << "success";
    } catch (std::exception const& e) {
        cout << e.what();
    }
    delete fileNameBuffer;
}
void receiveResponse(int clientSock, const string &fileName) {
    // Before Step 4: Open file
    ofstream outFile;
    try {
        cout << endl << "Open file status: ";
        outFile.open(fileName, ofstream::out);
        outFile.good() ? cout << "success" : throw std::runtime_error("error");
    } catch (std::exception const& e) {
        cout << e.what();
    }
    // Step 4a: Receive content
    char *recvBuffer;
    char *receivedMessage = NULL;
    int recvBytes = 0;
    recvBuffer = new char[CHUNK_SIZE];
    string save_status = "success";
    bool msg_recv_flag = true;

    cout << endl << "Received text:" << endl;

    try {
        recvBytes = recv(clientSock, recvBuffer, CHUNK_SIZE, 0);
        if (recvBytes < 0) {
            cout << endl << "Error receiving message!" << endl;
        }

        while (recvBytes > 0)
        {
            int receivedMessageLength;
            // Handle file not found
            if (recvBytes < strlen(recvBuffer)) {
                receivedMessageLength = recvBytes;
            } else {
                receivedMessageLength = strlen(recvBuffer);
            }
            receivedMessage = new char[receivedMessageLength+1];
            strncpy(receivedMessage, recvBuffer, receivedMessageLength);
            *std::find(receivedMessage, receivedMessage + receivedMessageLength,'\0') = '\0'; //End string.
            cout << receivedMessage;

            // Save to text file
            for (int i = 0; i < receivedMessageLength; ++i) {
                if (outFile.good()) {
                    outFile << receivedMessage[i];
                } else {
                    save_status = "error";
                }
            }
            if(recvBytes < CHUNK_SIZE) {
                break;
            }
            recvBytes = recv(clientSock, recvBuffer, CHUNK_SIZE, 0);
            if (strlen(recvBuffer) <= 0) break;
            if (recvBytes < 0) {
                msg_recv_flag = false;
                throw "Error receiving message!";
                break;
            }
        }
    } catch (const string& err) {
        cout << err;
    }

    cout << endl << "Save text status: ";
    cout << save_status;
    if (msg_recv_flag) {
        cout << endl << "Receive File " << fileName <<  " From the Server Successful!";
    }

    delete recvBuffer;
    delete receivedMessage;
    outFile.close();
    cout << endl;
}
void sendAndReceiveData(int clientSock) {
    string fileName;
    cin.ignore(); // Ignore newline from previous input

    while (1) {
        //Step 3: Send request to file server
        cout << endl << "Input the file name to be requested from the server:" << endl;
        // Get as string and convert to C string for buffer
        getline(cin, fileName);
        if (fileName.compare("exit") == 0) break;
        sendRequest(clientSock, fileName);

        //Step 4: Receive content and save to a file
        receiveResponse(clientSock, fileName);
    }
}
void closeConnection(int clientSock) {
    closesocket(clientSock); //  Close connection.
    cout << endl << "Connection closed." << endl;
}
