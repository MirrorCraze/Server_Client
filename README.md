# Server Client App

This program is created by Michael Lim and Phudis Dawieang

The "main" program is in 55334795-55411086.cpp
All functions used are in client_methods.cpp

The program is built using CMake.
CMakeList.txt includes all executable command to run the program. (Similar to MakeFile)

Client.exe is in the folder "cmake-build-debug"

Development Environment: Windows 10 Build 1903
Editor: JetBrains CLion with Visual Studio 2019 Community Toolchain
Build Target: Visual Studio 16 2019
C compiler identification: MSVC 19.23.28106.4
CXX compiler identification: MSVC 19.23.28106.4
Language: C/C++

## Build and Run Instructions
1. Unpack zip file into a folder
2. With cmake installed, run `cmake . && cmake --build .`
3. The executable can be found inside the Debug folder of the project directory. The executable file is named Client.exe.


## Program Execution Instruction
- IP address must be in IPv4
- Connection between client and server will be tried for maximum 10 times. After that, if connection still fails, the program will exit.
- If the file is not found but the connection still success, then file will be created with the name given and with the text "File" inside the file.
- Type "exit" when program asked "Input the file name to be requested from the server:" to close the connection.
