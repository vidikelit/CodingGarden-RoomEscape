#include "game/coin.h"

Coin::Coin(int x, int y) : x_(x), y_(y) {}

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
