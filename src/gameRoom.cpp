#include "game/gameRoom.h"
#include <BearLibTerminal.h>
#include <vector>

void GameRoom::renderRoom() {
  terminal_layer(0);
  terminal_clear();
  // отрисовка
  wall.render();
  for (auto door : doors) door.render();
  // отрисовка тайлами
  if (isTiles()) {
    // левый верхний
    symbol_tiles_ = 0xE00;
    tilesWall.clear();
    terminal_set("0xE00: resources/tilesets/tilesetRoom.png, size=64x64");
    terminal_put(0, 6, 0xE00);
    terminal_put(20, 6, 0xE01);
    terminal_put(0, 16, 0xE02);
    terminal_put(20, 16, 0xE03);
    //  отрисовка стен комнаты X
    // верхняя полоса
    symbol_tiles_ = 0xE07;
    tilesWall.clear();
    for (unsigned int i = 0; i < 6; i++) tilesWall.push_back(symbol_tiles_++);
    for (int i = 0; i < getRoomSizeX() - 2; i++) {
      terminal_put(i + 1, 6, tilesWall.at(0));
      tilesWall.push_back(tilesWall.at(0));
      tilesWall.erase(tilesWall.begin());
    }
    // нижняя полоса
    symbol_tiles_ = 0xE0E;
    tilesWall.clear();
    for (unsigned int i = 0; i < 5; i++) tilesWall.push_back(symbol_tiles_++);
    for (int i = 0; i < getRoomSizeX() - 2; i++) {
      terminal_put(i + 1, getRoomSizeY() - 1, tilesWall.at(0));
      tilesWall.push_back(tilesWall.at(0));
      tilesWall.erase(tilesWall.begin());
    }
    // отрисовка стен комнаты Y
    // левая полоса
    symbol_tiles_ = 0xE15;
    tilesWall.clear();
    for (unsigned int i = 0; i < 2; i++) tilesWall.push_back(symbol_tiles_++);
    for (int i = 0; i < getRoomSizeY() - 8; i++) {
      terminal_put(0, 7 + i, tilesWall.at(0));
      tilesWall.push_back(tilesWall.at(0));
      tilesWall.erase(tilesWall.begin());
    }
    // правая полоса
    symbol_tiles_ = 0xE1C;
    tilesWall.clear();
    for (unsigned int i = 0; i < 2; i++) tilesWall.push_back(symbol_tiles_++);
    for (int i = 0; i < getRoomSizeY() - 8; i++) {
      terminal_put(getRoomSizeX() - 1, 7 + i, tilesWall.at(0));
      tilesWall.push_back(tilesWall.at(0));
      tilesWall.erase(tilesWall.begin());
    }
    // отрисовка пола
    // угловые
    terminal_put(1, 7, 0xE04);
    terminal_put(19, 7, 0xE18);
    terminal_put(1, 15, 0xE19);
    terminal_put(19, 15, 0xE1A);
    // центральная заливка
    for (int i = 0; i < getRoomSizeX() - 4; i++) {
      for (int j = 0; j < getRoomSizeY() - 10; j++) {
        terminal_put(i + 2, j + 8, 0xE1B);
      }
    }
    // верхняя полоса
    symbol_tiles_ = 0xE05;
    tilesWall.clear();
    for (unsigned int i = 0; i < 2; i++) tilesWall.push_back(symbol_tiles_++);
    for (int i = 0; i < getRoomSizeX() - 4; i++) {
      terminal_put(i + 2, 7, tilesWall.at(0));
      tilesWall.push_back(tilesWall.at(0));
      tilesWall.erase(tilesWall.begin());
    }
    // нижняя полоса
    symbol_tiles_ = 0xE1E;
    tilesWall.clear();
    for (unsigned int i = 0; i < 2; i++) tilesWall.push_back(symbol_tiles_++);
    for (int i = 0; i < getRoomSizeX() - 4; i++) {
      terminal_put(i + 2, getRoomSizeY() - 2, tilesWall.at(0));
      tilesWall.push_back(tilesWall.at(0));
      tilesWall.erase(tilesWall.begin());
    }
    // левая полоса
    for (int i = 0; i < getRoomSizeY() - 10; i++) {
      terminal_put(1, 8 + i, 0xE17);
    }
    // правая полоса
    for (int i = 0; i < getRoomSizeY() - 10; i++) {
      terminal_put(getRoomSizeX() - 2, 8 + i, 0xE20);
    }
    // двери
    for (unsigned i = 0; i < doors.size(); i++) {
      // верх
      if (doors.at(i).getX() == 10 && doors.at(i).getY() == 6)
        terminal_put(doors.at(i).getX(), doors.at(i).getY(), 0xE21);
      // низ
      if (doors.at(i).getX() == 10 && doors.at(i).getY() == 16)
        terminal_put(doors.at(i).getX(), doors.at(i).getY(), 0xE22);
      // лево
      if (doors.at(i).getX() == 0 && doors.at(i).getY() == 11)
        terminal_put(doors.at(i).getX(), doors.at(i).getY(), 0xE23);
      // право
      if (doors.at(i).getX() == 20 && doors.at(i).getY() == 11)
        terminal_put(doors.at(i).getX(), doors.at(i).getY(), 0xE24);
    }
  }
}
void GameRoom::renderCoin() {
  terminal_layer(1);
  for (auto coin : coins) coin.render();
}
void GameRoom::renderElevator() {
  elevator.render();
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
void GameRoom::setDoorCoord(int x, int y) {
  doors.push_back(Door(x, y));
}
void GameRoom::setCoinCoord(int x, int y) {
  coins.push_back(Coin(x, y));
}
int GameRoom::getWallSymbol() {
  int symbol = wall.getSymbolWall();
  return symbol;
}
int GameRoom::getDoorSymbol() {
  return doors.at(0).getSymbolDoor();
}
int GameRoom::getCoinSymbol() {
  return coins.at(0).getSymbolCoin();
}
int GameRoom::getCoinCount() {
  return static_cast<int>(coins.size());
}
void GameRoom::removeCoin(int i) {
  coins.erase(coins.begin() + i);
}
bool GameRoom::isTiles() const {
  return tiles_;
}
void GameRoom::setTiles(bool tiles) {
  tiles_ = tiles;
}
GameRoom::GameRoom(int x, int y) : x_(x), y_(y) {}
GameRoom::GameRoom() {}
std::vector<Door>& GameRoom::getDoors() {
  return doors;
}
std::vector<Coin>& GameRoom::getCoins() {
  return coins;
}
void GameRoom::setElevator() {
  elevator.setExit(true);
}
const Elevator& GameRoom::getElevator() const {
  return elevator;
}
