# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/naokotani/code/school/final-project-student-information-system-Naokotani

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/naokotani/code/school/final-project-student-information-system-Naokotani

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/codegen:
.PHONY : CMakeFiles/tests.dir/codegen

CMakeFiles/tests.dir/test/test.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test/test.cpp.o: test/test.cpp
CMakeFiles/tests.dir/test/test.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/naokotani/code/school/final-project-student-information-system-Naokotani/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test/test.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/test/test.cpp.o -MF CMakeFiles/tests.dir/test/test.cpp.o.d -o CMakeFiles/tests.dir/test/test.cpp.o -c /home/naokotani/code/school/final-project-student-information-system-Naokotani/test/test.cpp

CMakeFiles/tests.dir/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/test/test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naokotani/code/school/final-project-student-information-system-Naokotani/test/test.cpp > CMakeFiles/tests.dir/test/test.cpp.i

CMakeFiles/tests.dir/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test/test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naokotani/code/school/final-project-student-information-system-Naokotani/test/test.cpp -o CMakeFiles/tests.dir/test/test.cpp.s

CMakeFiles/tests.dir/src/calculate_mark.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/calculate_mark.cpp.o: src/calculate_mark.cpp
CMakeFiles/tests.dir/src/calculate_mark.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/naokotani/code/school/final-project-student-information-system-Naokotani/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/src/calculate_mark.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/src/calculate_mark.cpp.o -MF CMakeFiles/tests.dir/src/calculate_mark.cpp.o.d -o CMakeFiles/tests.dir/src/calculate_mark.cpp.o -c /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/calculate_mark.cpp

CMakeFiles/tests.dir/src/calculate_mark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/calculate_mark.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/calculate_mark.cpp > CMakeFiles/tests.dir/src/calculate_mark.cpp.i

CMakeFiles/tests.dir/src/calculate_mark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/calculate_mark.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/calculate_mark.cpp -o CMakeFiles/tests.dir/src/calculate_mark.cpp.s

CMakeFiles/tests.dir/src/print_class.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/print_class.cpp.o: src/print_class.cpp
CMakeFiles/tests.dir/src/print_class.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/naokotani/code/school/final-project-student-information-system-Naokotani/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/src/print_class.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/src/print_class.cpp.o -MF CMakeFiles/tests.dir/src/print_class.cpp.o.d -o CMakeFiles/tests.dir/src/print_class.cpp.o -c /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/print_class.cpp

CMakeFiles/tests.dir/src/print_class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/print_class.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/print_class.cpp > CMakeFiles/tests.dir/src/print_class.cpp.i

CMakeFiles/tests.dir/src/print_class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/print_class.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/print_class.cpp -o CMakeFiles/tests.dir/src/print_class.cpp.s

CMakeFiles/tests.dir/src/delete_student.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/src/delete_student.cpp.o: src/delete_student.cpp
CMakeFiles/tests.dir/src/delete_student.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/naokotani/code/school/final-project-student-information-system-Naokotani/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tests.dir/src/delete_student.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/src/delete_student.cpp.o -MF CMakeFiles/tests.dir/src/delete_student.cpp.o.d -o CMakeFiles/tests.dir/src/delete_student.cpp.o -c /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/delete_student.cpp

CMakeFiles/tests.dir/src/delete_student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/src/delete_student.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/delete_student.cpp > CMakeFiles/tests.dir/src/delete_student.cpp.i

CMakeFiles/tests.dir/src/delete_student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/src/delete_student.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/naokotani/code/school/final-project-student-information-system-Naokotani/src/delete_student.cpp -o CMakeFiles/tests.dir/src/delete_student.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test/test.cpp.o" \
"CMakeFiles/tests.dir/src/calculate_mark.cpp.o" \
"CMakeFiles/tests.dir/src/print_class.cpp.o" \
"CMakeFiles/tests.dir/src/delete_student.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/test/test.cpp.o
tests: CMakeFiles/tests.dir/src/calculate_mark.cpp.o
tests: CMakeFiles/tests.dir/src/print_class.cpp.o
tests: CMakeFiles/tests.dir/src/delete_student.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: CMakeFiles/tests.dir/compiler_depend.ts
tests: /usr/lib/libCatch2Main.a
tests: /usr/lib/libCatch2.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/naokotani/code/school/final-project-student-information-system-Naokotani/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /home/naokotani/code/school/final-project-student-information-system-Naokotani && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/naokotani/code/school/final-project-student-information-system-Naokotani /home/naokotani/code/school/final-project-student-information-system-Naokotani /home/naokotani/code/school/final-project-student-information-system-Naokotani /home/naokotani/code/school/final-project-student-information-system-Naokotani /home/naokotani/code/school/final-project-student-information-system-Naokotani/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tests.dir/depend
