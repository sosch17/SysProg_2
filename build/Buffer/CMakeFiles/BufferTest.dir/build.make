# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build

# Include any dependencies generated for this target.
include Buffer/CMakeFiles/BufferTest.dir/depend.make

# Include the progress variables for this target.
include Buffer/CMakeFiles/BufferTest.dir/progress.make

# Include the compile flags for this target's objects.
include Buffer/CMakeFiles/BufferTest.dir/flags.make

Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o: Buffer/CMakeFiles/BufferTest.dir/flags.make
Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o: ../Buffer/src/TestBuffer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Buffer && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o -c /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Buffer/src/TestBuffer.cpp

Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.i"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Buffer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Buffer/src/TestBuffer.cpp > CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.i

Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.s"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Buffer && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Buffer/src/TestBuffer.cpp -o CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.s

Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.requires:
.PHONY : Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.requires

Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.provides: Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.requires
	$(MAKE) -f Buffer/CMakeFiles/BufferTest.dir/build.make Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.provides.build
.PHONY : Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.provides

Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.provides.build: Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o

# Object files for target BufferTest
BufferTest_OBJECTS = \
"CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o"

# External object files for target BufferTest
BufferTest_EXTERNAL_OBJECTS =

Buffer/BufferTest: Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o
Buffer/BufferTest: Buffer/CMakeFiles/BufferTest.dir/build.make
Buffer/BufferTest: Buffer/libBufferLib.a
Buffer/BufferTest: Buffer/CMakeFiles/BufferTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable BufferTest"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Buffer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BufferTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Buffer/CMakeFiles/BufferTest.dir/build: Buffer/BufferTest
.PHONY : Buffer/CMakeFiles/BufferTest.dir/build

Buffer/CMakeFiles/BufferTest.dir/requires: Buffer/CMakeFiles/BufferTest.dir/src/TestBuffer.cpp.o.requires
.PHONY : Buffer/CMakeFiles/BufferTest.dir/requires

Buffer/CMakeFiles/BufferTest.dir/clean:
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Buffer && $(CMAKE_COMMAND) -P CMakeFiles/BufferTest.dir/cmake_clean.cmake
.PHONY : Buffer/CMakeFiles/BufferTest.dir/clean

Buffer/CMakeFiles/BufferTest.dir/depend:
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2 /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Buffer /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Buffer /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Buffer/CMakeFiles/BufferTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Buffer/CMakeFiles/BufferTest.dir/depend

