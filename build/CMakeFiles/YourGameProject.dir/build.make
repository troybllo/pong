# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/troybello/Projects/practice/pong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/troybello/Projects/practice/pong/build

# Include any dependencies generated for this target.
include CMakeFiles/YourGameProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/YourGameProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/YourGameProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YourGameProject.dir/flags.make

CMakeFiles/YourGameProject.dir/src/main.cpp.o: CMakeFiles/YourGameProject.dir/flags.make
CMakeFiles/YourGameProject.dir/src/main.cpp.o: /Users/troybello/Projects/practice/pong/src/main.cpp
CMakeFiles/YourGameProject.dir/src/main.cpp.o: CMakeFiles/YourGameProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/troybello/Projects/practice/pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/YourGameProject.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/YourGameProject.dir/src/main.cpp.o -MF CMakeFiles/YourGameProject.dir/src/main.cpp.o.d -o CMakeFiles/YourGameProject.dir/src/main.cpp.o -c /Users/troybello/Projects/practice/pong/src/main.cpp

CMakeFiles/YourGameProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/YourGameProject.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/troybello/Projects/practice/pong/src/main.cpp > CMakeFiles/YourGameProject.dir/src/main.cpp.i

CMakeFiles/YourGameProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/YourGameProject.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/troybello/Projects/practice/pong/src/main.cpp -o CMakeFiles/YourGameProject.dir/src/main.cpp.s

CMakeFiles/YourGameProject.dir/src/Game.cpp.o: CMakeFiles/YourGameProject.dir/flags.make
CMakeFiles/YourGameProject.dir/src/Game.cpp.o: /Users/troybello/Projects/practice/pong/src/Game.cpp
CMakeFiles/YourGameProject.dir/src/Game.cpp.o: CMakeFiles/YourGameProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/troybello/Projects/practice/pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/YourGameProject.dir/src/Game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/YourGameProject.dir/src/Game.cpp.o -MF CMakeFiles/YourGameProject.dir/src/Game.cpp.o.d -o CMakeFiles/YourGameProject.dir/src/Game.cpp.o -c /Users/troybello/Projects/practice/pong/src/Game.cpp

CMakeFiles/YourGameProject.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/YourGameProject.dir/src/Game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/troybello/Projects/practice/pong/src/Game.cpp > CMakeFiles/YourGameProject.dir/src/Game.cpp.i

CMakeFiles/YourGameProject.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/YourGameProject.dir/src/Game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/troybello/Projects/practice/pong/src/Game.cpp -o CMakeFiles/YourGameProject.dir/src/Game.cpp.s

# Object files for target YourGameProject
YourGameProject_OBJECTS = \
"CMakeFiles/YourGameProject.dir/src/main.cpp.o" \
"CMakeFiles/YourGameProject.dir/src/Game.cpp.o"

# External object files for target YourGameProject
YourGameProject_EXTERNAL_OBJECTS =

YourGameProject: CMakeFiles/YourGameProject.dir/src/main.cpp.o
YourGameProject: CMakeFiles/YourGameProject.dir/src/Game.cpp.o
YourGameProject: CMakeFiles/YourGameProject.dir/build.make
YourGameProject: /Library/Frameworks/SDL2.framework/Versions/A/SDL2
YourGameProject: CMakeFiles/YourGameProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/troybello/Projects/practice/pong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable YourGameProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/YourGameProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YourGameProject.dir/build: YourGameProject
.PHONY : CMakeFiles/YourGameProject.dir/build

CMakeFiles/YourGameProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YourGameProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YourGameProject.dir/clean

CMakeFiles/YourGameProject.dir/depend:
	cd /Users/troybello/Projects/practice/pong/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/troybello/Projects/practice/pong /Users/troybello/Projects/practice/pong /Users/troybello/Projects/practice/pong/build /Users/troybello/Projects/practice/pong/build /Users/troybello/Projects/practice/pong/build/CMakeFiles/YourGameProject.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/YourGameProject.dir/depend

