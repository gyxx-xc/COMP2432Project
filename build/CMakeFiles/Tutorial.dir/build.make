# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/gyxx/myProject/c/os/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gyxx/myProject/c/os/project/build

# Include any dependencies generated for this target.
include CMakeFiles/Tutorial.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tutorial.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tutorial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tutorial.dir/flags.make

CMakeFiles/Tutorial.dir/src/input.c.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/input.c.o: /home/gyxx/myProject/c/os/project/src/input.c
CMakeFiles/Tutorial.dir/src/input.c.o: CMakeFiles/Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gyxx/myProject/c/os/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Tutorial.dir/src/input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Tutorial.dir/src/input.c.o -MF CMakeFiles/Tutorial.dir/src/input.c.o.d -o CMakeFiles/Tutorial.dir/src/input.c.o -c /home/gyxx/myProject/c/os/project/src/input.c

CMakeFiles/Tutorial.dir/src/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Tutorial.dir/src/input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gyxx/myProject/c/os/project/src/input.c > CMakeFiles/Tutorial.dir/src/input.c.i

CMakeFiles/Tutorial.dir/src/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Tutorial.dir/src/input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gyxx/myProject/c/os/project/src/input.c -o CMakeFiles/Tutorial.dir/src/input.c.s

CMakeFiles/Tutorial.dir/src/main.c.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/main.c.o: /home/gyxx/myProject/c/os/project/src/main.c
CMakeFiles/Tutorial.dir/src/main.c.o: CMakeFiles/Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gyxx/myProject/c/os/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Tutorial.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Tutorial.dir/src/main.c.o -MF CMakeFiles/Tutorial.dir/src/main.c.o.d -o CMakeFiles/Tutorial.dir/src/main.c.o -c /home/gyxx/myProject/c/os/project/src/main.c

CMakeFiles/Tutorial.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Tutorial.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gyxx/myProject/c/os/project/src/main.c > CMakeFiles/Tutorial.dir/src/main.c.i

CMakeFiles/Tutorial.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Tutorial.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gyxx/myProject/c/os/project/src/main.c -o CMakeFiles/Tutorial.dir/src/main.c.s

CMakeFiles/Tutorial.dir/src/output.c.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/output.c.o: /home/gyxx/myProject/c/os/project/src/output.c
CMakeFiles/Tutorial.dir/src/output.c.o: CMakeFiles/Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gyxx/myProject/c/os/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Tutorial.dir/src/output.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Tutorial.dir/src/output.c.o -MF CMakeFiles/Tutorial.dir/src/output.c.o.d -o CMakeFiles/Tutorial.dir/src/output.c.o -c /home/gyxx/myProject/c/os/project/src/output.c

CMakeFiles/Tutorial.dir/src/output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Tutorial.dir/src/output.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gyxx/myProject/c/os/project/src/output.c > CMakeFiles/Tutorial.dir/src/output.c.i

CMakeFiles/Tutorial.dir/src/output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Tutorial.dir/src/output.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gyxx/myProject/c/os/project/src/output.c -o CMakeFiles/Tutorial.dir/src/output.c.s

CMakeFiles/Tutorial.dir/src/runpls.c.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/runpls.c.o: /home/gyxx/myProject/c/os/project/src/runpls.c
CMakeFiles/Tutorial.dir/src/runpls.c.o: CMakeFiles/Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gyxx/myProject/c/os/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Tutorial.dir/src/runpls.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Tutorial.dir/src/runpls.c.o -MF CMakeFiles/Tutorial.dir/src/runpls.c.o.d -o CMakeFiles/Tutorial.dir/src/runpls.c.o -c /home/gyxx/myProject/c/os/project/src/runpls.c

CMakeFiles/Tutorial.dir/src/runpls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Tutorial.dir/src/runpls.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gyxx/myProject/c/os/project/src/runpls.c > CMakeFiles/Tutorial.dir/src/runpls.c.i

CMakeFiles/Tutorial.dir/src/runpls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Tutorial.dir/src/runpls.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gyxx/myProject/c/os/project/src/runpls.c -o CMakeFiles/Tutorial.dir/src/runpls.c.s

CMakeFiles/Tutorial.dir/src/tools.c.o: CMakeFiles/Tutorial.dir/flags.make
CMakeFiles/Tutorial.dir/src/tools.c.o: /home/gyxx/myProject/c/os/project/src/tools.c
CMakeFiles/Tutorial.dir/src/tools.c.o: CMakeFiles/Tutorial.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gyxx/myProject/c/os/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Tutorial.dir/src/tools.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Tutorial.dir/src/tools.c.o -MF CMakeFiles/Tutorial.dir/src/tools.c.o.d -o CMakeFiles/Tutorial.dir/src/tools.c.o -c /home/gyxx/myProject/c/os/project/src/tools.c

CMakeFiles/Tutorial.dir/src/tools.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Tutorial.dir/src/tools.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gyxx/myProject/c/os/project/src/tools.c > CMakeFiles/Tutorial.dir/src/tools.c.i

CMakeFiles/Tutorial.dir/src/tools.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Tutorial.dir/src/tools.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gyxx/myProject/c/os/project/src/tools.c -o CMakeFiles/Tutorial.dir/src/tools.c.s

# Object files for target Tutorial
Tutorial_OBJECTS = \
"CMakeFiles/Tutorial.dir/src/input.c.o" \
"CMakeFiles/Tutorial.dir/src/main.c.o" \
"CMakeFiles/Tutorial.dir/src/output.c.o" \
"CMakeFiles/Tutorial.dir/src/runpls.c.o" \
"CMakeFiles/Tutorial.dir/src/tools.c.o"

# External object files for target Tutorial
Tutorial_EXTERNAL_OBJECTS =

Tutorial: CMakeFiles/Tutorial.dir/src/input.c.o
Tutorial: CMakeFiles/Tutorial.dir/src/main.c.o
Tutorial: CMakeFiles/Tutorial.dir/src/output.c.o
Tutorial: CMakeFiles/Tutorial.dir/src/runpls.c.o
Tutorial: CMakeFiles/Tutorial.dir/src/tools.c.o
Tutorial: CMakeFiles/Tutorial.dir/build.make
Tutorial: CMakeFiles/Tutorial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/gyxx/myProject/c/os/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Tutorial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tutorial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tutorial.dir/build: Tutorial
.PHONY : CMakeFiles/Tutorial.dir/build

CMakeFiles/Tutorial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tutorial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tutorial.dir/clean

CMakeFiles/Tutorial.dir/depend:
	cd /home/gyxx/myProject/c/os/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gyxx/myProject/c/os/project /home/gyxx/myProject/c/os/project /home/gyxx/myProject/c/os/project/build /home/gyxx/myProject/c/os/project/build /home/gyxx/myProject/c/os/project/build/CMakeFiles/Tutorial.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Tutorial.dir/depend
