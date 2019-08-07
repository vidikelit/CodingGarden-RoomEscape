#ifndef INCLUDE_GAME_GAMEROOM_H_
#define INCLUDE_GAME_GAMEROOM_H_

#include <vector>
#include "game/coin.h"
#include "game/door.h"
#include "game/wall.h"
#include "game/elevator.h"

class GameRoom {
 private:
  int x_;
  int y_;
  int room_size_x_ = 21;
  int room_size_y_ = 17;

  bool tiles_ = true;
  int symbol_tiles_;

  Wall wall;
  Elevator elevator;
  std::vector<Door> doors{};
  std::vector<Coin> coins{};
  std::vector<int> tilesWall;
  std::vector<int> tilesDoors;

 public:
  void renderRoom();
  void renderCoin();
  void renderElevator();
  void setDoorCoord(int x, int y);
  void setCoinCoord(int x, int y);
  std::vector<Door>& getDoors();
  std::vector<Coin>& getCoins();
  const Elevator& getElevator() const;

  int getRoomSizeX() const;
  int getRoomSizeY() const;
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  int getWallSymbol();
  int getDoorSymbol();
  int getCoinSymbol();
  int getCoinCount();
  void removeCoin(int i);
  bool isTiles() const;
  void setTiles(bool tiles);
  void setElevator();
  GameRoom(int x, int y);
  GameRoom();
};

#endif  // INCLUDE_GAME_GAMEROOM_H_
