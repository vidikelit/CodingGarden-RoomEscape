#ifndef INCLUDE_GAME_GAMEMAP_H_
#define INCLUDE_GAME_GAMEMAP_H_

#include <vector>
#include "game/gameRoom.h"

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
  void generatorMap();
  void generatorRoom();
  void generatorDoor(int x, int y, int i);
  void generatorCoin(int n);
  void setDoorCoin();
  void render(int n);
  void renderCoin(int n);
  void formLevel(int x, int y);

  int getPointX() const;
  void setPointX(int pointX);
  int getPointY() const;
  void setPointY(int pointY);
  int getNumberRoom() const;
  void setNumberRoom(int numberRoom);
  int getAllCoin();
  const std::vector<GameRoom>& getRooms() const;
  GameRoom& getCurrentRoom();
};

#endif  // INCLUDE_GAME_GAMEMAP_H_
