#include "game/miniMap.h"
#include <BearLibTerminal.h>

void MiniMap::render() {
  terminal_set("0xA00: ./resources/tilesets/tilesetMiniMap.png, size=64x64");
  terminal_layer(3);
  terminal_clear_area(1, 1, 3, 3);
  for (unsigned int i = 0; i < miniRooms.size(); i++) {
    terminal_put(pos_render_x_ + miniRooms.at(i).getX(), pos_render_y_ + miniRooms.at(i).getY(), 0xA00);
  }
  terminal_put(pos_render_x_, pos_render_y_, 0xA01);
  terminal_put(0, 0, 0xE00);
  terminal_put(4, 0, 0xE01);
  terminal_put(0, 4, 0xE02);
  terminal_put(4, 4, 0xE03);
  terminal_crop(0, 0, 5, 5);
  for (int i = 1; i < 4; i++) {
    terminal_put(i, 0, 0xE07);
    terminal_put(i, 4, 0xE0E);
  }
  for (int i = 1; i < 4; i++) {
    terminal_put(0, i, 0xE15);
    terminal_put(4, i, 0xE1C);
  }
}
void MiniMap::generatorMiniMap() {
  for (unsigned int i = 1; i < gameMap->getRooms().size(); i++) {
    miniRooms.push_back(MiniRooms(gameMap->getRooms().at(i).getX() / 21, gameMap->getRooms().at(i).getY() / 17));
  }
}
void MiniMap::setRoomsCoords(int x_, int y_) {
  miniRooms.push_back(MiniRooms(x_, y_));
}
MiniMap::MiniMap(GameMap *gameMap) : gameMap(gameMap) {}
MiniMap::MiniMap() {}
void MiniMap::mapMove(int i) {
  // вверх
  if (i == 0) {
    for (unsigned int j = 0; j < miniRooms.size(); j++) {
      miniRooms.at(j).setY(miniRooms.at(j).getY() + 1);
    }
  }
  // вниз
  if (i == 1) {
    for (unsigned int j = 0; j < miniRooms.size(); j++) {
      miniRooms.at(j).setY(miniRooms.at(j).getY() - 1);
    }
  }
  // влево
  if (i == 2) {
    for (unsigned int j = 0; j < miniRooms.size(); j++) {
      miniRooms.at(j).setX(miniRooms.at(j).getX() + 1);
    }
  }
  // вправо
  if (i == 3) {
    for (unsigned int j = 0; j < miniRooms.size(); j++) {
      miniRooms.at(j).setX(miniRooms.at(j).getX() - 1);
    }
  }
}
