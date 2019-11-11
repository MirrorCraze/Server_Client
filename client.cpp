//
// Created by craze on 11/11/2019.
//

#include <iostream>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <ws2def.h>
#include<string>
#define portnum 12345
#define FILE_SIZE 500
#define BUFFER_SIZE 1024
using namespace std;
int main()
{
    int fam_addr = AF_INET; //Address family
    int s = socket(fam_addr,SOCK_STREAM,0);
    if(s<0)
    {
        cout << "Socket Creation Error";
        return -1;
    }
    string data_rec = "";
    struct sockaddr_in cli_addr;
    cli_addr.sin_family = fam_addr;
    cli_addr.sin_port = htons(portnum);
    cout << "Input the IP Address: ";
    string ser_ip_addr;
    cin >> ser_ip_addr;
    if(inet_pton(fam_addr,ser_ip_addr.c_str(),&cli_addr.sin_addr) <=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

}