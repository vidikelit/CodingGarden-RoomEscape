#ifndef INCLUDE_GAME_GAMEROOM_H_
#define INCLUDE_GAME_GAMEROOM_H_

#include <vector>
#include "game/coin.h"

class GameRoom {
 private:
  std::vector<Coin> coins{};
  // координаты комнаты
  int x_;
  int y_;
  // размер по осям
  int room_size_x_ = 30;
  int room_size_y_ = 20;

  int symbol_wall_ = 0x23;
  int symbol_door_ = 0x3E;
  int symbol_exit_ = 0x25;

  // выход в комнате
  int exitDoor_[1][2] = {{15, 12}};
  bool exit_ = false;

 public:
  // двери в комнате
  bool doors[4] = {false, false, false, false};
  int doorsCoords[4][2] = {{15, 5}, {15, room_size_y_}, {0, 12}, {room_size_x_, 12}};

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
