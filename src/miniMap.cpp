#include "game/miniMap.h"
#include <BearLibTerminal.h>

void MiniMap::render() {
  terminal_layer(3);
  terminal_clear_area(0, 0, 5, 5);
  if (isTiles()) {
    terminal_set("0xA00: ./resources/tilesets/tilesetMiniMap.png, size=64x64");
    // комнаты
    for (unsigned int i = 0; i < miniRooms.size(); i++) {
      terminal_put(miniRooms.at(i).getPosRenderX() + miniRooms.at(i).getX(),
                   miniRooms.at(i).getPosRenderY() + miniRooms.at(i).getY(), 0xA00);
    }
    terminal_put(miniRooms.at(0).getPosRenderX(), miniRooms.at(0).getPosRenderY(), 0xA01);
    // угловые
    terminal_put(0, 0, 0xE00);
    terminal_put(4, 0, 0xE01);
    terminal_put(0, 4, 0xE02);
    terminal_put(4, 4, 0xE03);
    for (int i = 1; i < 4; i++) {
      terminal_put(i, 0, 0xE07);
      terminal_put(i, 4, 0xE0E);
    }
    for (int i = 1; i < 4; i++) {
      terminal_put(0, i, 0xE15);
      terminal_put(4, i, 0xE1C);
    }
  } else {
    // команты
    for (auto room : miniRooms) room.render();
    // угловые
    terminal_clear_area(0, 0, 1, 5);
    terminal_clear_area(0, 0, 5, 1);
    terminal_clear_area(4, 0, 1, 5);
    terminal_clear_area(0, 4, 5, 1);
    for (int i = 0; i < getMiniMapSize(); i++) {
      terminal_put(i, 0, getSymbolMap());
      terminal_put(i, 4, getSymbolMap());
      terminal_put(0, i, getSymbolMap());
      terminal_put(4, i, getSymbolMap());
    }
  }
  terminal_crop(0, 0, 5, 5);
}
void MiniMap::generatorMiniMap() {
  for (unsigned int i = 1; i < gameMap->getRooms().size(); i++) {
    miniRooms.push_back(MiniRooms(gameMap->getRooms().at(i).getX() / 21, gameMap->getRooms().at(i).getY() / 17));
  }
}
void MiniMap::setRoomsCoords(int x_, int y_) {
  miniRooms.push_back(MiniRooms(x_, y_));
}
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
int MiniMap::getSymbolMap() const {
  return symbol_map_;
}
int MiniMap::getMiniMapSize() const {
  return mini_map_size_;
}
bool MiniMap::isTiles() const {
  return tiles_;
}
void MiniMap::setTiles(bool tiles) {
  tiles_ = tiles;
}
MiniMap::MiniMap(GameMap *gameMap) : gameMap(gameMap) {}
MiniMap::MiniMap() {}
