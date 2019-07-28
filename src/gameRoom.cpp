#include "game/gameRoom.h"
#include <BearLibTerminal.h>

void GameRoom::renderRoom() {
  //    отрисовка стен комнаты X
  for (int i = 0; i <= getRoomSizeX(); i++) {
    terminal_put(i, 5, symbol_wall_);
    terminal_put(i, getRoomSizeY(), symbol_wall_);
  }
  //    отрисовка стен комнаты Y
  for (int i = 1; i <= getRoomSizeY() - 6; i++) {
    terminal_put(0, i + 5, symbol_wall_);
    terminal_put(getRoomSizeX(), i + 5, symbol_wall_);
  }
}
void GameRoom::renderDoor() {
  //    отрисовка дверей
  for (int i = 0; i <= 4; i++) {
    if (doors[i]) {
      terminal_put(doorsCoords[i][0], doorsCoords[i][1], symbol_door_);
    }
  }
}
// действия с монетами в комнате
void GameRoom::renderCoin() {
  for (auto &coin : coins) {
    terminal_layer(1);
    terminal_put(coin.getX(), coin.getY(), coin.getSymbolCoin());
    terminal_layer(0);
  }
}
Coin GameRoom::getCoin(int i) {
  return coins.at(i);
}
int GameRoom::getCoinCount() {
  return static_cast<int>(coins.size());
}
void GameRoom::pushCoin(Coin coin) {
  coins.push_back(coin);
}
void GameRoom::removeCoin(int i) {
  coins.erase(coins.begin() + i);
}
// выход
void GameRoom::renderExit() {
  if (isExit()) {
    terminal_put(exitDoor_[0][0], exitDoor_[0][1], symbol_exit_);
  }
}
bool GameRoom::isExit() const {
  return exit_;
}
void GameRoom::setExit(bool exit) {
  exit_ = exit;
}
int GameRoom::getSymbolExit() const {
  return symbol_exit_;
}
int GameRoom::getRoomSizeX() const {
  return room_size_x_;
}
int GameRoom::getRoomSizeY() const {
  return room_size_y_;
}
int GameRoom::getX() const {
  return x_;
}
int GameRoom::getY() const {
  return y_;
}
void GameRoom::setX(int x) {
  x_ = x;
}
void GameRoom::setY(int y) {
  y_ = y;
}
GameRoom::GameRoom(int x, int y) : x_(x), y_(y) {}
