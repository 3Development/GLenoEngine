# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/leno/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/223.8617.54/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/leno/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/223.8617.54/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug

# Include any dependencies generated for this target.
include examples/CMakeFiles/example1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include examples/CMakeFiles/example1.dir/compiler_depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/example1.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/example1.dir/flags.make

examples/CMakeFiles/example1.dir/maintest.cpp.o: examples/CMakeFiles/example1.dir/flags.make
examples/CMakeFiles/example1.dir/maintest.cpp.o: /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/examples/maintest.cpp
examples/CMakeFiles/example1.dir/maintest.cpp.o: examples/CMakeFiles/example1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object examples/CMakeFiles/example1.dir/maintest.cpp.o"
	cd /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT examples/CMakeFiles/example1.dir/maintest.cpp.o -MF CMakeFiles/example1.dir/maintest.cpp.o.d -o CMakeFiles/example1.dir/maintest.cpp.o -c /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/examples/maintest.cpp

examples/CMakeFiles/example1.dir/maintest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example1.dir/maintest.cpp.i"
	cd /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/examples/maintest.cpp > CMakeFiles/example1.dir/maintest.cpp.i

examples/CMakeFiles/example1.dir/maintest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example1.dir/maintest.cpp.s"
	cd /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/examples/maintest.cpp -o CMakeFiles/example1.dir/maintest.cpp.s

# Object files for target example1
example1_OBJECTS = \
"CMakeFiles/example1.dir/maintest.cpp.o"

# External object files for target example1
example1_EXTERNAL_OBJECTS =

examples/example1: examples/CMakeFiles/example1.dir/maintest.cpp.o
examples/example1: examples/CMakeFiles/example1.dir/build.make
examples/example1: src/libcore.a
examples/example1: /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/thirdparty/glfw-3.3.8/build/src/libglfw3.a
examples/example1: /usr/lib64/libSM.so
examples/example1: /usr/lib64/libICE.so
examples/example1: /usr/lib64/libX11.so
examples/example1: /usr/lib64/libXext.so
examples/example1: /usr/lib64/librt.a
examples/example1: /usr/lib64/libm.so
examples/example1: /usr/lib64/libX11.so
examples/example1: /usr/lib64/libXext.so
examples/example1: /usr/lib64/librt.a
examples/example1: /usr/lib64/libm.so
examples/example1: examples/CMakeFiles/example1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example1"
	cd /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/example1.dir/build: examples/example1
.PHONY : examples/CMakeFiles/example1.dir/build

examples/CMakeFiles/example1.dir/clean:
	cd /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/examples && $(CMAKE_COMMAND) -P CMakeFiles/example1.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/example1.dir/clean

examples/CMakeFiles/example1.dir/depend:
	cd /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1 /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/examples /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/examples /home/leno/DevelopmentCenter/Projects/GameDev/GameEngines/LenoEngine/v1/cmake-build-debug/examples/CMakeFiles/example1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/example1.dir/depend

