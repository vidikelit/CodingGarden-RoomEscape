# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/vidik/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vidik/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vidik/CLionProjects/RoomEscape

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vidik/CLionProjects/RoomEscape

# Include any dependencies generated for this target.
include CMakeFiles/RoomEscape.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RoomEscape.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RoomEscape.dir/flags.make

CMakeFiles/RoomEscape.dir/src/main.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RoomEscape.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/main.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/main.cpp

CMakeFiles/RoomEscape.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/main.cpp > CMakeFiles/RoomEscape.dir/src/main.cpp.i

CMakeFiles/RoomEscape.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/main.cpp -o CMakeFiles/RoomEscape.dir/src/main.cpp.s

CMakeFiles/RoomEscape.dir/src/controls.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/controls.cpp.o: src/controls.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RoomEscape.dir/src/controls.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/controls.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/controls.cpp

CMakeFiles/RoomEscape.dir/src/controls.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/controls.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/controls.cpp > CMakeFiles/RoomEscape.dir/src/controls.cpp.i

CMakeFiles/RoomEscape.dir/src/controls.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/controls.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/controls.cpp -o CMakeFiles/RoomEscape.dir/src/controls.cpp.s

CMakeFiles/RoomEscape.dir/src/player.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/player.cpp.o: src/player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RoomEscape.dir/src/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/player.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/player.cpp

CMakeFiles/RoomEscape.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/player.cpp > CMakeFiles/RoomEscape.dir/src/player.cpp.i

CMakeFiles/RoomEscape.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/player.cpp -o CMakeFiles/RoomEscape.dir/src/player.cpp.s

CMakeFiles/RoomEscape.dir/src/window.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/window.cpp.o: src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/RoomEscape.dir/src/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/window.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/window.cpp

CMakeFiles/RoomEscape.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/window.cpp > CMakeFiles/RoomEscape.dir/src/window.cpp.i

CMakeFiles/RoomEscape.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/window.cpp -o CMakeFiles/RoomEscape.dir/src/window.cpp.s

CMakeFiles/RoomEscape.dir/src/room.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/room.cpp.o: src/room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/RoomEscape.dir/src/room.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/room.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/room.cpp

CMakeFiles/RoomEscape.dir/src/room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/room.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/room.cpp > CMakeFiles/RoomEscape.dir/src/room.cpp.i

CMakeFiles/RoomEscape.dir/src/room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/room.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/room.cpp -o CMakeFiles/RoomEscape.dir/src/room.cpp.s

CMakeFiles/RoomEscape.dir/src/map.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/map.cpp.o: src/map.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/RoomEscape.dir/src/map.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/map.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/map.cpp

CMakeFiles/RoomEscape.dir/src/map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/map.cpp > CMakeFiles/RoomEscape.dir/src/map.cpp.i

CMakeFiles/RoomEscape.dir/src/map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/map.cpp -o CMakeFiles/RoomEscape.dir/src/map.cpp.s

CMakeFiles/RoomEscape.dir/src/coin.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/coin.cpp.o: src/coin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/RoomEscape.dir/src/coin.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/coin.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/coin.cpp

CMakeFiles/RoomEscape.dir/src/coin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/coin.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/coin.cpp > CMakeFiles/RoomEscape.dir/src/coin.cpp.i

CMakeFiles/RoomEscape.dir/src/coin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/coin.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/coin.cpp -o CMakeFiles/RoomEscape.dir/src/coin.cpp.s

CMakeFiles/RoomEscape.dir/src/interaction.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/interaction.cpp.o: src/interaction.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/RoomEscape.dir/src/interaction.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/interaction.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/interaction.cpp

CMakeFiles/RoomEscape.dir/src/interaction.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/interaction.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/interaction.cpp > CMakeFiles/RoomEscape.dir/src/interaction.cpp.i

CMakeFiles/RoomEscape.dir/src/interaction.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/interaction.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/interaction.cpp -o CMakeFiles/RoomEscape.dir/src/interaction.cpp.s

CMakeFiles/RoomEscape.dir/src/gameInit.cpp.o: CMakeFiles/RoomEscape.dir/flags.make
CMakeFiles/RoomEscape.dir/src/gameInit.cpp.o: src/gameInit.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/RoomEscape.dir/src/gameInit.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RoomEscape.dir/src/gameInit.cpp.o -c /home/vidik/CLionProjects/RoomEscape/src/gameInit.cpp

CMakeFiles/RoomEscape.dir/src/gameInit.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RoomEscape.dir/src/gameInit.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vidik/CLionProjects/RoomEscape/src/gameInit.cpp > CMakeFiles/RoomEscape.dir/src/gameInit.cpp.i

CMakeFiles/RoomEscape.dir/src/gameInit.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RoomEscape.dir/src/gameInit.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vidik/CLionProjects/RoomEscape/src/gameInit.cpp -o CMakeFiles/RoomEscape.dir/src/gameInit.cpp.s

# Object files for target RoomEscape
RoomEscape_OBJECTS = \
"CMakeFiles/RoomEscape.dir/src/main.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/controls.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/player.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/window.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/room.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/map.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/coin.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/interaction.cpp.o" \
"CMakeFiles/RoomEscape.dir/src/gameInit.cpp.o"

# External object files for target RoomEscape
RoomEscape_EXTERNAL_OBJECTS =

RoomEscape: CMakeFiles/RoomEscape.dir/src/main.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/controls.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/player.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/window.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/room.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/map.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/coin.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/interaction.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/src/gameInit.cpp.o
RoomEscape: CMakeFiles/RoomEscape.dir/build.make
RoomEscape: lib/BearLibTerminal/Linux64/libBearLibTerminal.so
RoomEscape: CMakeFiles/RoomEscape.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vidik/CLionProjects/RoomEscape/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable RoomEscape"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RoomEscape.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RoomEscape.dir/build: RoomEscape

.PHONY : CMakeFiles/RoomEscape.dir/build

CMakeFiles/RoomEscape.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RoomEscape.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RoomEscape.dir/clean

CMakeFiles/RoomEscape.dir/depend:
	cd /home/vidik/CLionProjects/RoomEscape && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vidik/CLionProjects/RoomEscape /home/vidik/CLionProjects/RoomEscape /home/vidik/CLionProjects/RoomEscape /home/vidik/CLionProjects/RoomEscape /home/vidik/CLionProjects/RoomEscape/CMakeFiles/RoomEscape.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RoomEscape.dir/depend

