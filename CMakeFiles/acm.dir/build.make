# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fzhan/work/Algo-Collection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fzhan/work/Algo-Collection

# Include any dependencies generated for this target.
include CMakeFiles/acm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/acm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/acm.dir/flags.make

CMakeFiles/acm.dir/main.cpp.o: CMakeFiles/acm.dir/flags.make
CMakeFiles/acm.dir/main.cpp.o: main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fzhan/work/Algo-Collection/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/acm.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/acm.dir/main.cpp.o -c /home/fzhan/work/Algo-Collection/main.cpp

CMakeFiles/acm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/acm.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fzhan/work/Algo-Collection/main.cpp > CMakeFiles/acm.dir/main.cpp.i

CMakeFiles/acm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/acm.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fzhan/work/Algo-Collection/main.cpp -o CMakeFiles/acm.dir/main.cpp.s

CMakeFiles/acm.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/acm.dir/main.cpp.o.requires

CMakeFiles/acm.dir/main.cpp.o.provides: CMakeFiles/acm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/acm.dir/build.make CMakeFiles/acm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/acm.dir/main.cpp.o.provides

CMakeFiles/acm.dir/main.cpp.o.provides.build: CMakeFiles/acm.dir/main.cpp.o

CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o: CMakeFiles/acm.dir/flags.make
CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o: include/dbg-1.20/dbg.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/fzhan/work/Algo-Collection/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o -c /home/fzhan/work/Algo-Collection/include/dbg-1.20/dbg.cpp

CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/fzhan/work/Algo-Collection/include/dbg-1.20/dbg.cpp > CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.i

CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/fzhan/work/Algo-Collection/include/dbg-1.20/dbg.cpp -o CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.s

CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.requires:
.PHONY : CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.requires

CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.provides: CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.requires
	$(MAKE) -f CMakeFiles/acm.dir/build.make CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.provides.build
.PHONY : CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.provides

CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.provides.build: CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o

# Object files for target acm
acm_OBJECTS = \
"CMakeFiles/acm.dir/main.cpp.o" \
"CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o"

# External object files for target acm
acm_EXTERNAL_OBJECTS =

acm: CMakeFiles/acm.dir/main.cpp.o
acm: CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o
acm: CMakeFiles/acm.dir/build.make
acm: CMakeFiles/acm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable acm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/acm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/acm.dir/build: acm
.PHONY : CMakeFiles/acm.dir/build

CMakeFiles/acm.dir/requires: CMakeFiles/acm.dir/main.cpp.o.requires
CMakeFiles/acm.dir/requires: CMakeFiles/acm.dir/include/dbg-1.20/dbg.cpp.o.requires
.PHONY : CMakeFiles/acm.dir/requires

CMakeFiles/acm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/acm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/acm.dir/clean

CMakeFiles/acm.dir/depend:
	cd /home/fzhan/work/Algo-Collection && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fzhan/work/Algo-Collection /home/fzhan/work/Algo-Collection /home/fzhan/work/Algo-Collection /home/fzhan/work/Algo-Collection /home/fzhan/work/Algo-Collection/CMakeFiles/acm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/acm.dir/depend

