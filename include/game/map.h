#ifndef INCLUDE_GAME_MAP_H_
#define INCLUDE_GAME_MAP_H_

#include <vector>
#include "game/room.h"

class Map {
 private:
  std::vector<Room> rooms{{0, 0}};
  int point_x_ = 0;
  int point_y_ = 0;

 public:
  int number_room_ = 0;
  int player_x_;
  int player_y_;

  void generateRoom();
  void generateDoor(int x, int y, int i);
  void generateCoin(int n);
  void generator();
  Room& getCurrentRoom();
  int getNumberRoom();
  int getAllCoin();
  void render(int n);
  void renderCoin(int n);
  void scanner(int x_p, int y_p, int n_r);
  void teleport(int i);
  void playerPos(int x_p, int y_p, int i);
  int getPointX() const;
  int getPointY() const;
  void setPointX(int pointX);
  void setPointY(int pointY);
  const std::vector<Room>& getRooms() const;
  void setRooms(Room room);
};

#endif  // INCLUDE_GAME_MAP_H_
