# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\GitHub\ServerClientFinale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitHub\ServerClientFinale\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\Server_Client_Finale.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Server_Client_Finale.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Server_Client_Finale.dir\flags.make

CMakeFiles\Server_Client_Finale.dir\client.cpp.obj: CMakeFiles\Server_Client_Finale.dir\flags.make
CMakeFiles\Server_Client_Finale.dir\client.cpp.obj: ..\client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\ServerClientFinale\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Server_Client_Finale.dir/client.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Server_Client_Finale.dir\client.cpp.obj /FdCMakeFiles\Server_Client_Finale.dir\ /FS -c D:\GitHub\ServerClientFinale\client.cpp
<<

CMakeFiles\Server_Client_Finale.dir\client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Client_Finale.dir/client.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Server_Client_Finale.dir\client.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitHub\ServerClientFinale\client.cpp
<<

CMakeFiles\Server_Client_Finale.dir\client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Client_Finale.dir/client.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Server_Client_Finale.dir\client.cpp.s /c D:\GitHub\ServerClientFinale\client.cpp
<<

CMakeFiles\Server_Client_Finale.dir\client_methods.cpp.obj: CMakeFiles\Server_Client_Finale.dir\flags.make
CMakeFiles\Server_Client_Finale.dir\client_methods.cpp.obj: ..\client_methods.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\ServerClientFinale\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Server_Client_Finale.dir/client_methods.cpp.obj"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\Server_Client_Finale.dir\client_methods.cpp.obj /FdCMakeFiles\Server_Client_Finale.dir\ /FS -c D:\GitHub\ServerClientFinale\client_methods.cpp
<<

CMakeFiles\Server_Client_Finale.dir\client_methods.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Server_Client_Finale.dir/client_methods.cpp.i"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe > CMakeFiles\Server_Client_Finale.dir\client_methods.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\GitHub\ServerClientFinale\client_methods.cpp
<<

CMakeFiles\Server_Client_Finale.dir\client_methods.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Server_Client_Finale.dir/client_methods.cpp.s"
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\Server_Client_Finale.dir\client_methods.cpp.s /c D:\GitHub\ServerClientFinale\client_methods.cpp
<<

# Object files for target Server_Client_Finale
Server_Client_Finale_OBJECTS = \
"CMakeFiles\Server_Client_Finale.dir\client.cpp.obj" \
"CMakeFiles\Server_Client_Finale.dir\client_methods.cpp.obj"

# External object files for target Server_Client_Finale
Server_Client_Finale_EXTERNAL_OBJECTS =

Server_Client_Finale.exe: CMakeFiles\Server_Client_Finale.dir\client.cpp.obj
Server_Client_Finale.exe: CMakeFiles\Server_Client_Finale.dir\client_methods.cpp.obj
Server_Client_Finale.exe: CMakeFiles\Server_Client_Finale.dir\build.make
Server_Client_Finale.exe: CMakeFiles\Server_Client_Finale.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitHub\ServerClientFinale\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Server_Client_Finale.exe"
	"C:\Program Files\JetBrains\CLion 2019.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\Server_Client_Finale.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1423~1.281\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\Server_Client_Finale.dir\objects1.rsp @<<
 /out:Server_Client_Finale.exe /implib:Server_Client_Finale.lib /pdb:D:\GitHub\ServerClientFinale\cmake-build-debug\Server_Client_Finale.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console ws2_32.lib wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\Server_Client_Finale.dir\build: Server_Client_Finale.exe

.PHONY : CMakeFiles\Server_Client_Finale.dir\build

CMakeFiles\Server_Client_Finale.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Server_Client_Finale.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Server_Client_Finale.dir\clean

CMakeFiles\Server_Client_Finale.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" D:\GitHub\ServerClientFinale D:\GitHub\ServerClientFinale D:\GitHub\ServerClientFinale\cmake-build-debug D:\GitHub\ServerClientFinale\cmake-build-debug D:\GitHub\ServerClientFinale\cmake-build-debug\CMakeFiles\Server_Client_Finale.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\Server_Client_Finale.dir\depend

