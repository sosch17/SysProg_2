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
include Automat/CMakeFiles/AutomatLib.dir/depend.make

# Include the progress variables for this target.
include Automat/CMakeFiles/AutomatLib.dir/progress.make

# Include the compile flags for this target's objects.
include Automat/CMakeFiles/AutomatLib.dir/flags.make

Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o: Automat/CMakeFiles/AutomatLib.dir/flags.make
Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o: ../Automat/src/Automat.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AutomatLib.dir/src/Automat.cpp.o -c /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Automat/src/Automat.cpp

Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AutomatLib.dir/src/Automat.cpp.i"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Automat/src/Automat.cpp > CMakeFiles/AutomatLib.dir/src/Automat.cpp.i

Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AutomatLib.dir/src/Automat.cpp.s"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Automat/src/Automat.cpp -o CMakeFiles/AutomatLib.dir/src/Automat.cpp.s

Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.requires:
.PHONY : Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.requires

Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.provides: Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.requires
	$(MAKE) -f Automat/CMakeFiles/AutomatLib.dir/build.make Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.provides.build
.PHONY : Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.provides

Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.provides.build: Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o

# Object files for target AutomatLib
AutomatLib_OBJECTS = \
"CMakeFiles/AutomatLib.dir/src/Automat.cpp.o"

# External object files for target AutomatLib
AutomatLib_EXTERNAL_OBJECTS =

Automat/libAutomatLib.a: Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o
Automat/libAutomatLib.a: Automat/CMakeFiles/AutomatLib.dir/build.make
Automat/libAutomatLib.a: Automat/CMakeFiles/AutomatLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libAutomatLib.a"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat && $(CMAKE_COMMAND) -P CMakeFiles/AutomatLib.dir/cmake_clean_target.cmake
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AutomatLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Automat/CMakeFiles/AutomatLib.dir/build: Automat/libAutomatLib.a
.PHONY : Automat/CMakeFiles/AutomatLib.dir/build

Automat/CMakeFiles/AutomatLib.dir/requires: Automat/CMakeFiles/AutomatLib.dir/src/Automat.cpp.o.requires
.PHONY : Automat/CMakeFiles/AutomatLib.dir/requires

Automat/CMakeFiles/AutomatLib.dir/clean:
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat && $(CMAKE_COMMAND) -P CMakeFiles/AutomatLib.dir/cmake_clean.cmake
.PHONY : Automat/CMakeFiles/AutomatLib.dir/clean

Automat/CMakeFiles/AutomatLib.dir/depend:
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2 /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Automat /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Automat/CMakeFiles/AutomatLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Automat/CMakeFiles/AutomatLib.dir/depend

