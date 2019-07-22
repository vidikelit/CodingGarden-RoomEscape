#ifndef INCLUDE_GAME_ROOM_H_
#define INCLUDE_GAME_ROOM_H_

#include <vector>
#include "game/coin.h"

class Room {
 private:
  int x_;
  int y_;
  // размер комнаты
  const int room_size_ = 20;
  const int symbol_wall_ = 0x23;
  const int symbol_door_ = 0x3E;
  const int symbol_exit_ = 0x45;
  std::vector<Coin> coins{};
  int exitDoor_[1][2] = {{10, 10}};
  bool exit_ = false;

 public:
  const int doorsCoords[4][2] = {{10, 0}, {10, 20}, {0, 10}, {20, 10}};
  bool doors[4] = {false, false, false, false};

  void renderRoom();
  void renderDoor();
  void renderCoin();
  void renderExit();
  void removeCoin(int i);
  void pushCoin(Coin coin);

  Room(int x, int y);
  int getCoinCount();
  Coin getCoin(int i);
  const int getRoomSize() const;
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  void setExit(bool exit);
  bool isExit() const;
  const int getSymbolExit() const;
};

#endif  // INCLUDE_GAME_ROOM_H_
