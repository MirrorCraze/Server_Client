cmake_minimum_required(VERSION 3.15)
project(Server_Client_New)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server_Client_New main.cpp server.cpp client.cpp)