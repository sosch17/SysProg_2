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
include Parser/CMakeFiles/ParserLib.dir/depend.make

# Include the progress variables for this target.
include Parser/CMakeFiles/ParserLib.dir/progress.make

# Include the compile flags for this target's objects.
include Parser/CMakeFiles/ParserLib.dir/flags.make

Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o: Parser/CMakeFiles/ParserLib.dir/flags.make
Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o: ../Parser/src/ParseTree.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o -c /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Parser/src/ParseTree.cpp

Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParserLib.dir/src/ParseTree.cpp.i"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Parser/src/ParseTree.cpp > CMakeFiles/ParserLib.dir/src/ParseTree.cpp.i

Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParserLib.dir/src/ParseTree.cpp.s"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Parser/src/ParseTree.cpp -o CMakeFiles/ParserLib.dir/src/ParseTree.cpp.s

Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.requires:
.PHONY : Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.requires

Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.provides: Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.requires
	$(MAKE) -f Parser/CMakeFiles/ParserLib.dir/build.make Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.provides.build
.PHONY : Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.provides

Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.provides.build: Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o

Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o: Parser/CMakeFiles/ParserLib.dir/flags.make
Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o: ../Parser/src/TypeCheck.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o -c /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Parser/src/TypeCheck.cpp

Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.i"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Parser/src/TypeCheck.cpp > CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.i

Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.s"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Parser/src/TypeCheck.cpp -o CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.s

Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.requires:
.PHONY : Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.requires

Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.provides: Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.requires
	$(MAKE) -f Parser/CMakeFiles/ParserLib.dir/build.make Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.provides.build
.PHONY : Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.provides

Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.provides.build: Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o

# Object files for target ParserLib
ParserLib_OBJECTS = \
"CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o" \
"CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o"

# External object files for target ParserLib
ParserLib_EXTERNAL_OBJECTS =

Parser/libParserLib.a: Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o
Parser/libParserLib.a: Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o
Parser/libParserLib.a: Parser/CMakeFiles/ParserLib.dir/build.make
Parser/libParserLib.a: Parser/CMakeFiles/ParserLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libParserLib.a"
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && $(CMAKE_COMMAND) -P CMakeFiles/ParserLib.dir/cmake_clean_target.cmake
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ParserLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Parser/CMakeFiles/ParserLib.dir/build: Parser/libParserLib.a
.PHONY : Parser/CMakeFiles/ParserLib.dir/build

Parser/CMakeFiles/ParserLib.dir/requires: Parser/CMakeFiles/ParserLib.dir/src/ParseTree.cpp.o.requires
Parser/CMakeFiles/ParserLib.dir/requires: Parser/CMakeFiles/ParserLib.dir/src/TypeCheck.cpp.o.requires
.PHONY : Parser/CMakeFiles/ParserLib.dir/requires

Parser/CMakeFiles/ParserLib.dir/clean:
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser && $(CMAKE_COMMAND) -P CMakeFiles/ParserLib.dir/cmake_clean.cmake
.PHONY : Parser/CMakeFiles/ParserLib.dir/clean

Parser/CMakeFiles/ParserLib.dir/depend:
	cd /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2 /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/Parser /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser /home/stud/lkt/fbi/brjo1022/workspace/SysProg_2/build/Parser/CMakeFiles/ParserLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Parser/CMakeFiles/ParserLib.dir/depend

