# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /userspace/apps/CLion/ch-0/211.6432.9/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /userspace/apps/CLion/ch-0/211.6432.9/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TwoApplicationsExchange.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TwoApplicationsExchange.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TwoApplicationsExchange.dir/flags.make

CMakeFiles/TwoApplicationsExchange.dir/main.cpp.o: CMakeFiles/TwoApplicationsExchange.dir/flags.make
CMakeFiles/TwoApplicationsExchange.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TwoApplicationsExchange.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TwoApplicationsExchange.dir/main.cpp.o -c /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/main.cpp

CMakeFiles/TwoApplicationsExchange.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TwoApplicationsExchange.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/main.cpp > CMakeFiles/TwoApplicationsExchange.dir/main.cpp.i

CMakeFiles/TwoApplicationsExchange.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TwoApplicationsExchange.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/main.cpp -o CMakeFiles/TwoApplicationsExchange.dir/main.cpp.s

# Object files for target TwoApplicationsExchange
TwoApplicationsExchange_OBJECTS = \
"CMakeFiles/TwoApplicationsExchange.dir/main.cpp.o"

# External object files for target TwoApplicationsExchange
TwoApplicationsExchange_EXTERNAL_OBJECTS =

TwoApplicationsExchange: CMakeFiles/TwoApplicationsExchange.dir/main.cpp.o
TwoApplicationsExchange: CMakeFiles/TwoApplicationsExchange.dir/build.make
TwoApplicationsExchange: CMakeFiles/TwoApplicationsExchange.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TwoApplicationsExchange"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TwoApplicationsExchange.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TwoApplicationsExchange.dir/build: TwoApplicationsExchange

.PHONY : CMakeFiles/TwoApplicationsExchange.dir/build

CMakeFiles/TwoApplicationsExchange.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TwoApplicationsExchange.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TwoApplicationsExchange.dir/clean

CMakeFiles/TwoApplicationsExchange.dir/depend:
	cd /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/cmake-build-debug /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/cmake-build-debug /home/ray/Documents/DTTAH/windows/CLion/TwoApplicationsExchange/cmake-build-debug/CMakeFiles/TwoApplicationsExchange.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TwoApplicationsExchange.dir/depend

