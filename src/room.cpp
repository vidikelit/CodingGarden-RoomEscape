#include "game/room.h"
#include <BearLibTerminal.h>

Room::Room(int x, int y) : x_(x), y_(y) {}

void Room::renderRoom() {
  //    отрисовка стен комнаты
  for (int i = 0; i <= getRoomSize(); i++) {
    terminal_put(i, 0, symbol_wall_);
    terminal_put(i, getRoomSize(), symbol_wall_);
    terminal_put(0, i, symbol_wall_);
    terminal_put(getRoomSize(), i, symbol_wall_);
  }
}

void Room::renderDoor() {
  //    отрисовка дверей
  for (int i = 0; i <= 4; i++) {
    if (doors[i]) {
      terminal_put(doorsCoords[i][0], doorsCoords[i][1], symbol_door_);
    }
  }
}

void Room::renderCoin() {
  for (auto &coin : coins) {
    terminal_layer(1);
    terminal_put(coin.getX(), coin.getY(), coin.getSymbolCoin());
    terminal_layer(0);
  }
}

void Room::renderExit() {
  if (isExit()) {
    terminal_put(exitDoor_[0][0], exitDoor_[0][1], symbol_exit_);
  }
}

const int Room::getRoomSize() const {
  return room_size_;
}

int Room::getX() const {
  return x_;
}

int Room::getY() const {
  return y_;
}

int Room::getCoinCount() {
  return static_cast<int>(coins.size());
}

Coin Room::getCoin(int i) {
  return coins.at(i);
}

void Room::removeCoin(int i) {
  coins.erase(coins.begin() + i);
}

void Room::pushCoin(Coin coin) {
  coins.push_back(coin);
}
void Room::setExit(bool exit) {
  exit_ = exit;
}
bool Room::isExit() const {
  return exit_;
}
const int Room::getSymbolExit() const {
  return symbol_exit_;
}
void Room::setX(int x) {
  x_ = x;
}
void Room::setY(int y) {
  y_ = y;
}
