#ifndef INCLUDE_GAME_GAMEMAP_H_
#define INCLUDE_GAME_GAMEMAP_H_

#include <vector>
#include "game/gameRoom.h"
#include "game/wall.h"

class GameMap {
 private:
  std::vector<GameRoom> rooms{{0, 0}};
  int x_ = 0;
  int y_ = 0;
  int number_room_ = 0;

  int minRooms = 3;
  int maxRooms = 6;

 public:
  void update();
  void updateDoor();
  void generatorLevel();
  void generatorRoom();
  void generatorDoor(int n_room);
  void generatorCoin(int n_room);

  void formRoom(int x, int y);
  void formCoin(int x, int y, int r);
  int getAllCoin();

  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  int getNumberRoom() const;
  void setNumberRoom(int numberRoom);
  void setTilesRooms(bool tile);
  std::vector<GameRoom>& getRooms();
  GameRoom& getCurrentRoom();
};

#endif  // INCLUDE_GAME_GAMEMAP_H_
