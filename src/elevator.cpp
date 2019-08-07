#include "game/elevator.h"
#include <BearLibTerminal.h>

void Elevator::update() {}
void Elevator::render() {
  terminal_put(getX(), getY(), getSymbolEvelator());
}
int Elevator::getX() const {
  return x_;
}
void Elevator::setX(int x) {
  x_ = x;
}
int Elevator::getY() const {
  return y_;
}
void Elevator::setY(int y) {
  y_ = y;
}
int Elevator::getSymbolEvelator() const {
  return symbol_evelator_;
}
bool Elevator::isExit() const {
  return exit_;
}
void Elevator::setExit(bool exit) {
  exit_ = exit;
}
Elevator::Elevator(int x, int y) : x_(x), y_(y) {}
Elevator::Elevator() {}
