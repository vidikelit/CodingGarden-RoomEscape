#ifndef INCLUDE_GAME_GAMEROOM_H_
#define INCLUDE_GAME_GAMEROOM_H_

#include <vector>
#include "game/coin.h"

class GameRoom {
 private:
  std::vector<Coin> coins{};
  std::vector<int> tilesWall;
  std::vector<int> tilesDoors;
  // координаты комнаты
  int x_;
  int y_;
  // размер по осям
  int room_size_x_ = 21;
  int room_size_y_ = 17;

  int symbol_wall_ = 0xE00;
  int symbol_door_ = 0x3E;
  int symbol_exit_ = 0x25;

  // выход в комнате
  int exitDoor_[1][2] = {{10, 11}};
  bool exit_ = false;

 public:
  // двери в комнате
  bool doors[4] = {false, false, false, false};
  int doorsCoords[4][2] = {{10, 6}, {10, room_size_y_-1}, {0, 11}, {room_size_x_ - 1, 11}};

  void renderRoom();
  void renderDoor();

  // работа с монетами в комнате
  void renderCoin();
  Coin getCoin(int i);
  int getCoinCount();
  void pushCoin(Coin coin);
  void removeCoin(int i);

  // работа с выходом с уровня в комнате
  void renderExit();
  bool isExit() const;
  void setExit(bool exit);
  int getSymbolExit() const;

  int getRoomSizeX() const;
  int getRoomSizeY() const;
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  GameRoom(int x, int y);
};

#endif  // INCLUDE_GAME_GAMEROOM_H_
