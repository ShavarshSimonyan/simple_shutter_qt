# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/shavarsh/qt-projects/simple_shutter/unit_test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shavarsh/qt-projects/simple_shutter/unit_test

# Include any dependencies generated for this target.
include CMakeFiles/executeTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/executeTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/executeTests.dir/flags.make

CMakeFiles/executeTests.dir/main.cpp.o: CMakeFiles/executeTests.dir/flags.make
CMakeFiles/executeTests.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shavarsh/qt-projects/simple_shutter/unit_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/executeTests.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executeTests.dir/main.cpp.o -c /home/shavarsh/qt-projects/simple_shutter/unit_test/main.cpp

CMakeFiles/executeTests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executeTests.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shavarsh/qt-projects/simple_shutter/unit_test/main.cpp > CMakeFiles/executeTests.dir/main.cpp.i

CMakeFiles/executeTests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executeTests.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shavarsh/qt-projects/simple_shutter/unit_test/main.cpp -o CMakeFiles/executeTests.dir/main.cpp.s

CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.o: CMakeFiles/executeTests.dir/flags.make
CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.o: /home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shavarsh/qt-projects/simple_shutter/unit_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.o -c /home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp

CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp > CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.i

CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp -o CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.s

# Object files for target executeTests
executeTests_OBJECTS = \
"CMakeFiles/executeTests.dir/main.cpp.o" \
"CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.o"

# External object files for target executeTests
executeTests_EXTERNAL_OBJECTS =

executeTests: CMakeFiles/executeTests.dir/main.cpp.o
executeTests: CMakeFiles/executeTests.dir/home/shavarsh/qt-projects/simple_shutter/db_handling/dbData.cpp.o
executeTests: CMakeFiles/executeTests.dir/build.make
executeTests: /usr/lib/x86_64-linux-gnu/libgtest.a
executeTests: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8
executeTests: /usr/lib/x86_64-linux-gnu/libQt5Sql.so.5.12.8
executeTests: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.12.8
executeTests: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.12.8
executeTests: CMakeFiles/executeTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shavarsh/qt-projects/simple_shutter/unit_test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable executeTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/executeTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/executeTests.dir/build: executeTests

.PHONY : CMakeFiles/executeTests.dir/build

CMakeFiles/executeTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/executeTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/executeTests.dir/clean

CMakeFiles/executeTests.dir/depend:
	cd /home/shavarsh/qt-projects/simple_shutter/unit_test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shavarsh/qt-projects/simple_shutter/unit_test /home/shavarsh/qt-projects/simple_shutter/unit_test /home/shavarsh/qt-projects/simple_shutter/unit_test /home/shavarsh/qt-projects/simple_shutter/unit_test /home/shavarsh/qt-projects/simple_shutter/unit_test/CMakeFiles/executeTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/executeTests.dir/depend
