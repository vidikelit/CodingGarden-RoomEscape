# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vidik/CLionProjects/RoomEscape

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vidik/CLionProjects/RoomEscape

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/home/vidik/apps/clion-2019.1.4/bin/cmake/linux/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/vidik/CLionProjects/RoomEscape/CMakeFiles /home/vidik/CLionProjects/RoomEscape/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/vidik/CLionProjects/RoomEscape/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named RoomEscape

# Build rule for target.
RoomEscape: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 RoomEscape
.PHONY : RoomEscape

# fast build rule for target.
RoomEscape/fast:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/build
.PHONY : RoomEscape/fast

#=============================================================================
# Target rules for targets named lint

# Build rule for target.
lint: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 lint
.PHONY : lint

# fast build rule for target.
lint/fast:
	$(MAKE) -f CMakeFiles/lint.dir/build.make CMakeFiles/lint.dir/build
.PHONY : lint/fast

src/coin.o: src/coin.cpp.o

.PHONY : src/coin.o

# target to build an object file
src/coin.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/coin.cpp.o
.PHONY : src/coin.cpp.o

src/coin.i: src/coin.cpp.i

.PHONY : src/coin.i

# target to preprocess a source file
src/coin.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/coin.cpp.i
.PHONY : src/coin.cpp.i

src/coin.s: src/coin.cpp.s

.PHONY : src/coin.s

# target to generate assembly for a file
src/coin.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/coin.cpp.s
.PHONY : src/coin.cpp.s

src/controls.o: src/controls.cpp.o

.PHONY : src/controls.o

# target to build an object file
src/controls.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/controls.cpp.o
.PHONY : src/controls.cpp.o

src/controls.i: src/controls.cpp.i

.PHONY : src/controls.i

# target to preprocess a source file
src/controls.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/controls.cpp.i
.PHONY : src/controls.cpp.i

src/controls.s: src/controls.cpp.s

.PHONY : src/controls.s

# target to generate assembly for a file
src/controls.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/controls.cpp.s
.PHONY : src/controls.cpp.s

src/door.o: src/door.cpp.o

.PHONY : src/door.o

# target to build an object file
src/door.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/door.cpp.o
.PHONY : src/door.cpp.o

src/door.i: src/door.cpp.i

.PHONY : src/door.i

# target to preprocess a source file
src/door.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/door.cpp.i
.PHONY : src/door.cpp.i

src/door.s: src/door.cpp.s

.PHONY : src/door.s

# target to generate assembly for a file
src/door.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/door.cpp.s
.PHONY : src/door.cpp.s

src/elevator.o: src/elevator.cpp.o

.PHONY : src/elevator.o

# target to build an object file
src/elevator.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/elevator.cpp.o
.PHONY : src/elevator.cpp.o

src/elevator.i: src/elevator.cpp.i

.PHONY : src/elevator.i

# target to preprocess a source file
src/elevator.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/elevator.cpp.i
.PHONY : src/elevator.cpp.i

src/elevator.s: src/elevator.cpp.s

.PHONY : src/elevator.s

# target to generate assembly for a file
src/elevator.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/elevator.cpp.s
.PHONY : src/elevator.cpp.s

src/enemy.o: src/enemy.cpp.o

.PHONY : src/enemy.o

# target to build an object file
src/enemy.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/enemy.cpp.o
.PHONY : src/enemy.cpp.o

src/enemy.i: src/enemy.cpp.i

.PHONY : src/enemy.i

# target to preprocess a source file
src/enemy.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/enemy.cpp.i
.PHONY : src/enemy.cpp.i

src/enemy.s: src/enemy.cpp.s

.PHONY : src/enemy.s

# target to generate assembly for a file
src/enemy.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/enemy.cpp.s
.PHONY : src/enemy.cpp.s

src/gameLogic.o: src/gameLogic.cpp.o

.PHONY : src/gameLogic.o

# target to build an object file
src/gameLogic.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameLogic.cpp.o
.PHONY : src/gameLogic.cpp.o

src/gameLogic.i: src/gameLogic.cpp.i

.PHONY : src/gameLogic.i

# target to preprocess a source file
src/gameLogic.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameLogic.cpp.i
.PHONY : src/gameLogic.cpp.i

src/gameLogic.s: src/gameLogic.cpp.s

.PHONY : src/gameLogic.s

# target to generate assembly for a file
src/gameLogic.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameLogic.cpp.s
.PHONY : src/gameLogic.cpp.s

src/gameMap.o: src/gameMap.cpp.o

.PHONY : src/gameMap.o

# target to build an object file
src/gameMap.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameMap.cpp.o
.PHONY : src/gameMap.cpp.o

src/gameMap.i: src/gameMap.cpp.i

.PHONY : src/gameMap.i

# target to preprocess a source file
src/gameMap.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameMap.cpp.i
.PHONY : src/gameMap.cpp.i

src/gameMap.s: src/gameMap.cpp.s

.PHONY : src/gameMap.s

# target to generate assembly for a file
src/gameMap.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameMap.cpp.s
.PHONY : src/gameMap.cpp.s

src/gameMenu.o: src/gameMenu.cpp.o

.PHONY : src/gameMenu.o

# target to build an object file
src/gameMenu.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameMenu.cpp.o
.PHONY : src/gameMenu.cpp.o

src/gameMenu.i: src/gameMenu.cpp.i

.PHONY : src/gameMenu.i

# target to preprocess a source file
src/gameMenu.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameMenu.cpp.i
.PHONY : src/gameMenu.cpp.i

src/gameMenu.s: src/gameMenu.cpp.s

.PHONY : src/gameMenu.s

# target to generate assembly for a file
src/gameMenu.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameMenu.cpp.s
.PHONY : src/gameMenu.cpp.s

src/gameRoom.o: src/gameRoom.cpp.o

.PHONY : src/gameRoom.o

# target to build an object file
src/gameRoom.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameRoom.cpp.o
.PHONY : src/gameRoom.cpp.o

src/gameRoom.i: src/gameRoom.cpp.i

.PHONY : src/gameRoom.i

# target to preprocess a source file
src/gameRoom.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameRoom.cpp.i
.PHONY : src/gameRoom.cpp.i

src/gameRoom.s: src/gameRoom.cpp.s

.PHONY : src/gameRoom.s

# target to generate assembly for a file
src/gameRoom.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameRoom.cpp.s
.PHONY : src/gameRoom.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/miniMap.o: src/miniMap.cpp.o

.PHONY : src/miniMap.o

# target to build an object file
src/miniMap.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/miniMap.cpp.o
.PHONY : src/miniMap.cpp.o

src/miniMap.i: src/miniMap.cpp.i

.PHONY : src/miniMap.i

# target to preprocess a source file
src/miniMap.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/miniMap.cpp.i
.PHONY : src/miniMap.cpp.i

src/miniMap.s: src/miniMap.cpp.s

.PHONY : src/miniMap.s

# target to generate assembly for a file
src/miniMap.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/miniMap.cpp.s
.PHONY : src/miniMap.cpp.s

src/miniRooms.o: src/miniRooms.cpp.o

.PHONY : src/miniRooms.o

# target to build an object file
src/miniRooms.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/miniRooms.cpp.o
.PHONY : src/miniRooms.cpp.o

src/miniRooms.i: src/miniRooms.cpp.i

.PHONY : src/miniRooms.i

# target to preprocess a source file
src/miniRooms.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/miniRooms.cpp.i
.PHONY : src/miniRooms.cpp.i

src/miniRooms.s: src/miniRooms.cpp.s

.PHONY : src/miniRooms.s

# target to generate assembly for a file
src/miniRooms.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/miniRooms.cpp.s
.PHONY : src/miniRooms.cpp.s

src/player.o: src/player.cpp.o

.PHONY : src/player.o

# target to build an object file
src/player.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/player.cpp.o
.PHONY : src/player.cpp.o

src/player.i: src/player.cpp.i

.PHONY : src/player.i

# target to preprocess a source file
src/player.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/player.cpp.i
.PHONY : src/player.cpp.i

src/player.s: src/player.cpp.s

.PHONY : src/player.s

# target to generate assembly for a file
src/player.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/player.cpp.s
.PHONY : src/player.cpp.s

src/saver_loader.o: src/saver_loader.cpp.o

.PHONY : src/saver_loader.o

# target to build an object file
src/saver_loader.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/saver_loader.cpp.o
.PHONY : src/saver_loader.cpp.o

src/saver_loader.i: src/saver_loader.cpp.i

.PHONY : src/saver_loader.i

# target to preprocess a source file
src/saver_loader.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/saver_loader.cpp.i
.PHONY : src/saver_loader.cpp.i

src/saver_loader.s: src/saver_loader.cpp.s

.PHONY : src/saver_loader.s

# target to generate assembly for a file
src/saver_loader.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/saver_loader.cpp.s
.PHONY : src/saver_loader.cpp.s

src/wall.o: src/wall.cpp.o

.PHONY : src/wall.o

# target to build an object file
src/wall.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/wall.cpp.o
.PHONY : src/wall.cpp.o

src/wall.i: src/wall.cpp.i

.PHONY : src/wall.i

# target to preprocess a source file
src/wall.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/wall.cpp.i
.PHONY : src/wall.cpp.i

src/wall.s: src/wall.cpp.s

.PHONY : src/wall.s

# target to generate assembly for a file
src/wall.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/wall.cpp.s
.PHONY : src/wall.cpp.s

src/window.o: src/window.cpp.o

.PHONY : src/window.o

# target to build an object file
src/window.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/window.cpp.o
.PHONY : src/window.cpp.o

src/window.i: src/window.cpp.i

.PHONY : src/window.i

# target to preprocess a source file
src/window.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/window.cpp.i
.PHONY : src/window.cpp.i

src/window.s: src/window.cpp.s

.PHONY : src/window.s

# target to generate assembly for a file
src/window.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/window.cpp.s
.PHONY : src/window.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... RoomEscape"
	@echo "... lint"
	@echo "... src/coin.o"
	@echo "... src/coin.i"
	@echo "... src/coin.s"
	@echo "... src/controls.o"
	@echo "... src/controls.i"
	@echo "... src/controls.s"
	@echo "... src/door.o"
	@echo "... src/door.i"
	@echo "... src/door.s"
	@echo "... src/elevator.o"
	@echo "... src/elevator.i"
	@echo "... src/elevator.s"
	@echo "... src/enemy.o"
	@echo "... src/enemy.i"
	@echo "... src/enemy.s"
	@echo "... src/gameLogic.o"
	@echo "... src/gameLogic.i"
	@echo "... src/gameLogic.s"
	@echo "... src/gameMap.o"
	@echo "... src/gameMap.i"
	@echo "... src/gameMap.s"
	@echo "... src/gameMenu.o"
	@echo "... src/gameMenu.i"
	@echo "... src/gameMenu.s"
	@echo "... src/gameRoom.o"
	@echo "... src/gameRoom.i"
	@echo "... src/gameRoom.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/miniMap.o"
	@echo "... src/miniMap.i"
	@echo "... src/miniMap.s"
	@echo "... src/miniRooms.o"
	@echo "... src/miniRooms.i"
	@echo "... src/miniRooms.s"
	@echo "... src/player.o"
	@echo "... src/player.i"
	@echo "... src/player.s"
	@echo "... src/saver_loader.o"
	@echo "... src/saver_loader.i"
	@echo "... src/saver_loader.s"
	@echo "... src/wall.o"
	@echo "... src/wall.i"
	@echo "... src/wall.s"
	@echo "... src/window.o"
	@echo "... src/window.i"
	@echo "... src/window.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

