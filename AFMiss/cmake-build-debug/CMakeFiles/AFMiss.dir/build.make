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
CMAKE_COMMAND = /cygdrive/c/Users/MohammadYusuf/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/MohammadYusuf/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/e/Thesis/AFMiss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/e/Thesis/AFMiss/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/AFMiss.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AFMiss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AFMiss.dir/flags.make

CMakeFiles/AFMiss.dir/main.cpp.o: CMakeFiles/AFMiss.dir/flags.make
CMakeFiles/AFMiss.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/e/Thesis/AFMiss/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/AFMiss.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AFMiss.dir/main.cpp.o -c /cygdrive/e/Thesis/AFMiss/main.cpp

CMakeFiles/AFMiss.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AFMiss.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/e/Thesis/AFMiss/main.cpp > CMakeFiles/AFMiss.dir/main.cpp.i

CMakeFiles/AFMiss.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AFMiss.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/e/Thesis/AFMiss/main.cpp -o CMakeFiles/AFMiss.dir/main.cpp.s

# Object files for target AFMiss
AFMiss_OBJECTS = \
"CMakeFiles/AFMiss.dir/main.cpp.o"

# External object files for target AFMiss
AFMiss_EXTERNAL_OBJECTS =

AFMiss.exe: CMakeFiles/AFMiss.dir/main.cpp.o
AFMiss.exe: CMakeFiles/AFMiss.dir/build.make
AFMiss.exe: CMakeFiles/AFMiss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/e/Thesis/AFMiss/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable AFMiss.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AFMiss.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AFMiss.dir/build: AFMiss.exe

.PHONY : CMakeFiles/AFMiss.dir/build

CMakeFiles/AFMiss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AFMiss.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AFMiss.dir/clean

CMakeFiles/AFMiss.dir/depend:
	cd /cygdrive/e/Thesis/AFMiss/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/e/Thesis/AFMiss /cygdrive/e/Thesis/AFMiss /cygdrive/e/Thesis/AFMiss/cmake-build-debug /cygdrive/e/Thesis/AFMiss/cmake-build-debug /cygdrive/e/Thesis/AFMiss/cmake-build-debug/CMakeFiles/AFMiss.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AFMiss.dir/depend
