#include "game/door.h"
#include <BearLibTerminal.h>

void Door::update() {}
void Door::render() {
  terminal_clear_area(getX(), getY(), 1, 1);
  terminal_put(getX(), getY(), getSymbolDoor());
}
int Door::getX() const {
  return x_;
}
void Door::setX(int x) {
  x_ = x;
}
int Door::getY() const {
  return y_;
}
void Door::setY(int y) {
  y_ = y;
}
int Door::getSymbolDoor() const {
  return symbol_door_;
}
Door::Door(int x, int y) : x_(x), y_(y) {}
Door::Door() {}
