#include "game/coin.h"
#include <BearLibTerminal.h>

void Coin::update() {}
void Coin::render() {
  terminal_put(getX(), getY(), getSymbolCoin());
}

int Coin::getX() const {
  return x_;
}

void Coin::setX(int x) {
  x_ = x;
}

int Coin::getY() const {
  return y_;
}

void Coin::setY(int y) {
  y_ = y;
}

int Coin::getSymbolCoin() const {
  return symbol_coin_;
}
Coin::Coin(int x, int y) : x_(x), y_(y) {}
