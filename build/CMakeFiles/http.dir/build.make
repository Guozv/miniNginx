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
CMAKE_SOURCE_DIR = /mnt/c/Users/guo/Desktop/miniNginx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/guo/Desktop/miniNginx/build

# Include any dependencies generated for this target.
include CMakeFiles/http.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/http.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/http.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/http.dir/flags.make

CMakeFiles/http.dir/main.cpp.o: CMakeFiles/http.dir/flags.make
CMakeFiles/http.dir/main.cpp.o: ../main.cpp
CMakeFiles/http.dir/main.cpp.o: CMakeFiles/http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/guo/Desktop/miniNginx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/http.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/http.dir/main.cpp.o -MF CMakeFiles/http.dir/main.cpp.o.d -o CMakeFiles/http.dir/main.cpp.o -c /mnt/c/Users/guo/Desktop/miniNginx/main.cpp

CMakeFiles/http.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/http.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/guo/Desktop/miniNginx/main.cpp > CMakeFiles/http.dir/main.cpp.i

CMakeFiles/http.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/http.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/guo/Desktop/miniNginx/main.cpp -o CMakeFiles/http.dir/main.cpp.s

# Object files for target http
http_OBJECTS = \
"CMakeFiles/http.dir/main.cpp.o"

# External object files for target http
http_EXTERNAL_OBJECTS =

../bin/http: CMakeFiles/http.dir/main.cpp.o
../bin/http: CMakeFiles/http.dir/build.make
../bin/http: CMakeFiles/http.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/guo/Desktop/miniNginx/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/http"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/http.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/http.dir/build: ../bin/http
.PHONY : CMakeFiles/http.dir/build

CMakeFiles/http.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/http.dir/cmake_clean.cmake
.PHONY : CMakeFiles/http.dir/clean

CMakeFiles/http.dir/depend:
	cd /mnt/c/Users/guo/Desktop/miniNginx/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/guo/Desktop/miniNginx /mnt/c/Users/guo/Desktop/miniNginx /mnt/c/Users/guo/Desktop/miniNginx/build /mnt/c/Users/guo/Desktop/miniNginx/build /mnt/c/Users/guo/Desktop/miniNginx/build/CMakeFiles/http.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/http.dir/depend

