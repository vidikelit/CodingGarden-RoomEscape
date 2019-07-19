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
CMAKE_COMMAND = /home/vidik/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/vidik/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

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
	/home/vidik/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/home/vidik/apps/clion-2019.1.4/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
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

src/gameInit.o: src/gameInit.cpp.o

.PHONY : src/gameInit.o

# target to build an object file
src/gameInit.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameInit.cpp.o
.PHONY : src/gameInit.cpp.o

src/gameInit.i: src/gameInit.cpp.i

.PHONY : src/gameInit.i

# target to preprocess a source file
src/gameInit.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameInit.cpp.i
.PHONY : src/gameInit.cpp.i

src/gameInit.s: src/gameInit.cpp.s

.PHONY : src/gameInit.s

# target to generate assembly for a file
src/gameInit.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/gameInit.cpp.s
.PHONY : src/gameInit.cpp.s

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

src/map.o: src/map.cpp.o

.PHONY : src/map.o

# target to build an object file
src/map.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/map.cpp.o
.PHONY : src/map.cpp.o

src/map.i: src/map.cpp.i

.PHONY : src/map.i

# target to preprocess a source file
src/map.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/map.cpp.i
.PHONY : src/map.cpp.i

src/map.s: src/map.cpp.s

.PHONY : src/map.s

# target to generate assembly for a file
src/map.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/map.cpp.s
.PHONY : src/map.cpp.s

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

src/room.o: src/room.cpp.o

.PHONY : src/room.o

# target to build an object file
src/room.cpp.o:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/room.cpp.o
.PHONY : src/room.cpp.o

src/room.i: src/room.cpp.i

.PHONY : src/room.i

# target to preprocess a source file
src/room.cpp.i:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/room.cpp.i
.PHONY : src/room.cpp.i

src/room.s: src/room.cpp.s

.PHONY : src/room.s

# target to generate assembly for a file
src/room.cpp.s:
	$(MAKE) -f CMakeFiles/RoomEscape.dir/build.make CMakeFiles/RoomEscape.dir/src/room.cpp.s
.PHONY : src/room.cpp.s

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
	@echo "... src/gameInit.o"
	@echo "... src/gameInit.i"
	@echo "... src/gameInit.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/map.o"
	@echo "... src/map.i"
	@echo "... src/map.s"
	@echo "... src/player.o"
	@echo "... src/player.i"
	@echo "... src/player.s"
	@echo "... src/room.o"
	@echo "... src/room.i"
	@echo "... src/room.s"
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

