# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/makramgh/Desktop/Pepsi-Bot/workspace/src/perception/detection_interfaces

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/makramgh/Desktop/Pepsi-Bot/workspace/build/detection_interfaces

# Utility rule file for detection_interfaces_uninstall.

# Include any custom commands dependencies for this target.
include CMakeFiles/detection_interfaces_uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/detection_interfaces_uninstall.dir/progress.make

CMakeFiles/detection_interfaces_uninstall:
	/usr/bin/cmake -P /home/makramgh/Desktop/Pepsi-Bot/workspace/build/detection_interfaces/ament_cmake_uninstall_target/ament_cmake_uninstall_target.cmake

detection_interfaces_uninstall: CMakeFiles/detection_interfaces_uninstall
detection_interfaces_uninstall: CMakeFiles/detection_interfaces_uninstall.dir/build.make
.PHONY : detection_interfaces_uninstall

# Rule to build all files generated by this target.
CMakeFiles/detection_interfaces_uninstall.dir/build: detection_interfaces_uninstall
.PHONY : CMakeFiles/detection_interfaces_uninstall.dir/build

CMakeFiles/detection_interfaces_uninstall.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/detection_interfaces_uninstall.dir/cmake_clean.cmake
.PHONY : CMakeFiles/detection_interfaces_uninstall.dir/clean

CMakeFiles/detection_interfaces_uninstall.dir/depend:
	cd /home/makramgh/Desktop/Pepsi-Bot/workspace/build/detection_interfaces && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/makramgh/Desktop/Pepsi-Bot/workspace/src/perception/detection_interfaces /home/makramgh/Desktop/Pepsi-Bot/workspace/src/perception/detection_interfaces /home/makramgh/Desktop/Pepsi-Bot/workspace/build/detection_interfaces /home/makramgh/Desktop/Pepsi-Bot/workspace/build/detection_interfaces /home/makramgh/Desktop/Pepsi-Bot/workspace/build/detection_interfaces/CMakeFiles/detection_interfaces_uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/detection_interfaces_uninstall.dir/depend

