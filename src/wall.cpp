#include <BearLibTerminal.h>
#include "game/wall.h"
#include "game/gameRoom.h"

void Wall::update() {}
void Wall::render() {
  GameRoom gameRoom;
  for (int i = 0; i < gameRoom.getRoomSizeX(); i++) {
    terminal_put(0 + i, 6, getSymbolWall());
    terminal_put(0 + i, gameRoom.getRoomSizeY() - 1, getSymbolWall());
  }
  for (int i = 0; i < gameRoom.getRoomSizeY() - 8; i++) {
    terminal_put(0, 7 + i, getSymbolWall());
    terminal_put(gameRoom.getRoomSizeX() - 1, 7 + i, getSymbolWall());
  }
}
int Wall::getSymbolWall() const {
return symbol_wall_;
}
int Wall::getX() const {
  return x_;
}
void Wall::setX(int x) {
  x_ = x;
}
int Wall::getY() const {
  return y_;
}
void Wall::setY(int y) {
  y_ = y;
}
