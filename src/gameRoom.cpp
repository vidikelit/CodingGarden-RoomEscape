#include "game/gameRoom.h"
#include <BearLibTerminal.h>

void GameRoom::renderRoom() {
  // левый верхний
  symbol_wall_ = 0xE00;
  terminal_set("0xE00: resources/tilesets/tilesetWall.png, size=64x64");
  terminal_put(0, 6, 0xE00);
  terminal_put(20, 6, 0xE01);
  terminal_put(0, 16, 0xE02);
  terminal_put(20, 16, 0xE03);
  //  отрисовка стен комнаты X
  // верхняя полоса
  symbol_wall_ = 0xE07;
  tilesWall.clear();
  for (unsigned int i = 0; i < 6; i++) tilesWall.push_back(symbol_wall_++);
  for (int i = 0; i < getRoomSizeX() - 2; i++) {
    terminal_put(i + 1, 6, tilesWall.at(0));
    tilesWall.push_back(tilesWall.at(0));
    tilesWall.erase(tilesWall.begin());
  }
  // нижняя полоса
  symbol_wall_ = 0xE0E;
  tilesWall.clear();
  for (unsigned int i = 0; i < 5; i++) tilesWall.push_back(symbol_wall_++);
  for (int i = 0; i < getRoomSizeX() - 2; i++) {
    terminal_put(i + 1, getRoomSizeY() - 1, tilesWall.at(0));
    tilesWall.push_back(tilesWall.at(0));
    tilesWall.erase(tilesWall.begin());
  }
  // отрисовка стен комнаты Y
  // левая полоса
  symbol_wall_ = 0xE15;
  tilesWall.clear();
  for (unsigned int i = 0; i < 2; i++) tilesWall.push_back(symbol_wall_++);
  for (int i = 0; i < getRoomSizeY() - 8; i++) {
    terminal_put(0, 7 + i, tilesWall.at(0));
    tilesWall.push_back(tilesWall.at(0));
    tilesWall.erase(tilesWall.begin());
  }
  // правая полоса
  symbol_wall_ = 0xE1C;
  tilesWall.clear();
  for (unsigned int i = 0; i < 2; i++)
    tilesWall.push_back(symbol_wall_++);
  for (int i = 0; i < getRoomSizeY() - 8; i++) {
    terminal_put(getRoomSizeX() - 1, 7 + i, tilesWall.at(0));
    tilesWall.push_back(tilesWall.at(0));
    tilesWall.erase(tilesWall.begin());
  }
}
void GameRoom::renderDoor() {
  // отрисовка дверей
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
