# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\cpp\graph-algorithms\SortAlgo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\cpp\graph-algorithms\SortAlgo\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SortAlgo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SortAlgo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SortAlgo.dir/flags.make

CMakeFiles/SortAlgo.dir/main.cpp.obj: CMakeFiles/SortAlgo.dir/flags.make
CMakeFiles/SortAlgo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\cpp\graph-algorithms\SortAlgo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SortAlgo.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SortAlgo.dir\main.cpp.obj -c D:\Projects\cpp\graph-algorithms\SortAlgo\main.cpp

CMakeFiles/SortAlgo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SortAlgo.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\cpp\graph-algorithms\SortAlgo\main.cpp > CMakeFiles\SortAlgo.dir\main.cpp.i

CMakeFiles/SortAlgo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SortAlgo.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\cpp\graph-algorithms\SortAlgo\main.cpp -o CMakeFiles\SortAlgo.dir\main.cpp.s

# Object files for target SortAlgo
SortAlgo_OBJECTS = \
"CMakeFiles/SortAlgo.dir/main.cpp.obj"

# External object files for target SortAlgo
SortAlgo_EXTERNAL_OBJECTS =

SortAlgo.exe: CMakeFiles/SortAlgo.dir/main.cpp.obj
SortAlgo.exe: CMakeFiles/SortAlgo.dir/build.make
SortAlgo.exe: CMakeFiles/SortAlgo.dir/linklibs.rsp
SortAlgo.exe: CMakeFiles/SortAlgo.dir/objects1.rsp
SortAlgo.exe: CMakeFiles/SortAlgo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\cpp\graph-algorithms\SortAlgo\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SortAlgo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SortAlgo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SortAlgo.dir/build: SortAlgo.exe

.PHONY : CMakeFiles/SortAlgo.dir/build

CMakeFiles/SortAlgo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SortAlgo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SortAlgo.dir/clean

CMakeFiles/SortAlgo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\cpp\graph-algorithms\SortAlgo D:\Projects\cpp\graph-algorithms\SortAlgo D:\Projects\cpp\graph-algorithms\SortAlgo\cmake-build-debug D:\Projects\cpp\graph-algorithms\SortAlgo\cmake-build-debug D:\Projects\cpp\graph-algorithms\SortAlgo\cmake-build-debug\CMakeFiles\SortAlgo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SortAlgo.dir/depend

