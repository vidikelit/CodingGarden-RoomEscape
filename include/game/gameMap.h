#ifndef INCLUDE_GAME_GAMEMAP_H_
#define INCLUDE_GAME_GAMEMAP_H_

#include "game/gameRoom.h"
#include "vector"

class GameMap {
 private:
  // вектор с координатами комнат
  std::vector<GameRoom> rooms{{0, 0}};
  // координаты для генерации новой комнат
  int point_x_ = 0;
  int point_y_ = 0;
  // номер текущей комнаты
  int number_room_ = 0;

 public:
  // координаты игрока
  int player_x_;
  int player_y_;

  void generatorMap();
  void generatorRoom();
  void generatorDoor(int x, int y, int i);
  void generatorCoin(int n);
  void setDoorCoin();
  void render(int n);
  void renderCoin(int n);
  void scanner(int x_p, int y_p, int n_r);
  void teleport(int i);
  void playerPos(int x_p, int y_p, int i);

  int getPointX() const;
  void setPointX(int pointX);
  int getPointY() const;
  void setPointY(int pointY);
  int getNumberRoom() const;
  int getAllCoin();
  const std::vector<GameRoom>& getRooms() const;
  void setRooms(GameRoom gameRoom);
  GameRoom& getCurrentRoom();
};

#endif  // INCLUDE_GAME_GAMEMAP_H_
