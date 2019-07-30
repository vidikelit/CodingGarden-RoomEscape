#include "game/miniRooms.h"

int MiniRooms::getSymbolMiniRoom() const {
  return symbol_mini_room;
}
int MiniRooms::getX() const {
  return x_;
}
int MiniRooms::getY() const {
  return y_;
}
void MiniRooms::setX(int x) {
  x_ = x;
}
void MiniRooms::setY(int y) {
  y_ = y;
}
MiniRooms::MiniRooms(int x, int y) : x_(x), y_(y) {}
