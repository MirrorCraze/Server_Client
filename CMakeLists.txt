cmake_minimum_required(VERSION 3.15)
project(Server_Client_New)

set(CMAKE_CXX_STANDARD 14)
link_libraries(ws2_32 wsock32)
add_executable(Client 55334795-55411086.cpp client_methods.h client_methods.cpp)
