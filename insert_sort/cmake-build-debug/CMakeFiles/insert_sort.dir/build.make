# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/feng/CLionProjects/insert_sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/feng/CLionProjects/insert_sort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/insert_sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/insert_sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/insert_sort.dir/flags.make

CMakeFiles/insert_sort.dir/main.cpp.o: CMakeFiles/insert_sort.dir/flags.make
CMakeFiles/insert_sort.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/feng/CLionProjects/insert_sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/insert_sort.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/insert_sort.dir/main.cpp.o -c /Users/feng/CLionProjects/insert_sort/main.cpp

CMakeFiles/insert_sort.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/insert_sort.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/feng/CLionProjects/insert_sort/main.cpp > CMakeFiles/insert_sort.dir/main.cpp.i

CMakeFiles/insert_sort.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/insert_sort.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/feng/CLionProjects/insert_sort/main.cpp -o CMakeFiles/insert_sort.dir/main.cpp.s

# Object files for target insert_sort
insert_sort_OBJECTS = \
"CMakeFiles/insert_sort.dir/main.cpp.o"

# External object files for target insert_sort
insert_sort_EXTERNAL_OBJECTS =

insert_sort: CMakeFiles/insert_sort.dir/main.cpp.o
insert_sort: CMakeFiles/insert_sort.dir/build.make
insert_sort: CMakeFiles/insert_sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/feng/CLionProjects/insert_sort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable insert_sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/insert_sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/insert_sort.dir/build: insert_sort

.PHONY : CMakeFiles/insert_sort.dir/build

CMakeFiles/insert_sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/insert_sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/insert_sort.dir/clean

CMakeFiles/insert_sort.dir/depend:
	cd /Users/feng/CLionProjects/insert_sort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/feng/CLionProjects/insert_sort /Users/feng/CLionProjects/insert_sort /Users/feng/CLionProjects/insert_sort/cmake-build-debug /Users/feng/CLionProjects/insert_sort/cmake-build-debug /Users/feng/CLionProjects/insert_sort/cmake-build-debug/CMakeFiles/insert_sort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/insert_sort.dir/depend
