#include "game/miniMap.h"
#include <BearLibTerminal.h>

void MiniMap::render() {
  for (int i = 0; i < 5; i++) {
    terminal_put(i, 0, 0x2B);
    terminal_put(i, 4, 0x2B);
  }
  for (int i = 1; i < 4; i++) {
    terminal_put(0, i, 0x2B);
    terminal_put(4, i, 0x2B);
  }

  terminal_layer(1);
  terminal_clear_area(0, 0, 7, 5);
  terminal_set("0x100: ./resources/tilesets/tilesetHUD.png");
  for (unsigned int i = 0; i < miniRooms.size(); i++) {
    terminal_put(pos_render_x_ + miniRooms.at(i).getX(), pos_render_y_ + miniRooms.at(i).getY(), 0x100);
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
