# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/ics46/projects/project02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ics46/projects/project02/out

# Include any dependencies generated for this target.
include CMakeFiles/othelloaistudent.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/othelloaistudent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/othelloaistudent.dir/flags.make

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o: CMakeFiles/othelloaistudent.dir/flags.make
CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o: ../core/MyOthelloAI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics46/projects/project02/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o -c /home/ics46/projects/project02/core/MyOthelloAI.cpp

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics46/projects/project02/core/MyOthelloAI.cpp > CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.i

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics46/projects/project02/core/MyOthelloAI.cpp -o CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.s

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.requires:

.PHONY : CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.requires

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.provides: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.requires
	$(MAKE) -f CMakeFiles/othelloaistudent.dir/build.make CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.provides.build
.PHONY : CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.provides

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.provides.build: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o


CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o: CMakeFiles/othelloaistudent.dir/flags.make
CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o: ../core/MyOthelloAI2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ics46/projects/project02/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o"
	/usr/bin/clang++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o -c /home/ics46/projects/project02/core/MyOthelloAI2.cpp

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.i"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ics46/projects/project02/core/MyOthelloAI2.cpp > CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.i

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.s"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ics46/projects/project02/core/MyOthelloAI2.cpp -o CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.s

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.requires:

.PHONY : CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.requires

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.provides: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.requires
	$(MAKE) -f CMakeFiles/othelloaistudent.dir/build.make CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.provides.build
.PHONY : CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.provides

CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.provides.build: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o


# Object files for target othelloaistudent
othelloaistudent_OBJECTS = \
"CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o" \
"CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o"

# External object files for target othelloaistudent
othelloaistudent_EXTERNAL_OBJECTS =

lib/libothelloaistudent.a: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o
lib/libothelloaistudent.a: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o
lib/libothelloaistudent.a: CMakeFiles/othelloaistudent.dir/build.make
lib/libothelloaistudent.a: CMakeFiles/othelloaistudent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ics46/projects/project02/out/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library lib/libothelloaistudent.a"
	$(CMAKE_COMMAND) -P CMakeFiles/othelloaistudent.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/othelloaistudent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/othelloaistudent.dir/build: lib/libothelloaistudent.a

.PHONY : CMakeFiles/othelloaistudent.dir/build

CMakeFiles/othelloaistudent.dir/requires: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI.cpp.o.requires
CMakeFiles/othelloaistudent.dir/requires: CMakeFiles/othelloaistudent.dir/core/MyOthelloAI2.cpp.o.requires

.PHONY : CMakeFiles/othelloaistudent.dir/requires

CMakeFiles/othelloaistudent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/othelloaistudent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/othelloaistudent.dir/clean

CMakeFiles/othelloaistudent.dir/depend:
	cd /home/ics46/projects/project02/out && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ics46/projects/project02 /home/ics46/projects/project02 /home/ics46/projects/project02/out /home/ics46/projects/project02/out /home/ics46/projects/project02/out/CMakeFiles/othelloaistudent.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/othelloaistudent.dir/depend

