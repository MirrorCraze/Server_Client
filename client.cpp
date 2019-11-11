//
// Created by craze on 11/11/2019.
//

#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>

#define portnum 12345
#define FILE_SIZE 500
#define BUFFER_SIZE 1024

using namespace std;
int main()
{
    int s = socket(AF_INET,SOCK_STREAM,0);
    if(s==0)
    {
        cout << "Socket Creation Error";
        return -1;
    }

}