cmake_minimum_required(VERSION 3.14)
project(RoomEscape)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

find_package(BearLibTerminal REQUIRED)
include_directories(SYSTEM ${BLT_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
add_executable(RoomEscape src/main.cpp src/controls.cpp include/controls.h src/player.cpp include/player.h src/window.cpp include/window.h src/room.cpp include/room.h src/map.cpp include/map.h src/coin.cpp include/coin.h src/interaction.cpp include/interaction.h src/gameInit.cpp include/gameInit.h)

target_link_libraries(${PROJECT_NAME} ${BLT_LIBRARIES})

file(COPY ${BLT_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
