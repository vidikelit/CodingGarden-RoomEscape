#include "game/miniRooms.h"
#include <BearLibTerminal.h>

void MiniRooms::render() {
  terminal_put(getPosRenderX() + getX(), getPosRenderY() + getY(), getSymbolMiniRoom());
}
int MiniRooms::getSymbolMiniRoom() const {
  return symbol_mini_room_;
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
int MiniRooms::getPosRenderX() const {
  return pos_render_x_;
}
int MiniRooms::getPosRenderY() const {
  return pos_render_y_;
}
MiniRooms::MiniRooms(int x, int y) : x_(x), y_(y) {}
