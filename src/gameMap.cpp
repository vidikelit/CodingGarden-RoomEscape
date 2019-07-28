#include "game/gameMap.h"
#include <experimental/random>
#include <vector>
#include "game/player.h"

// генератор карты
void GameMap::generatorMap() {
  // генерируется от 5 до 10 комнат на карте
  for (int i = 0; i < std::experimental::randint(2, 4); i++) {
    bool a = true;
    int x = getPointX();
    int y = getPointY();
    generatorRoom();
    while (a) {
      a = false;
      for (unsigned int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).getX() == getPointX()) {
          if (rooms.at(i).getY() == getPointY()) {
            setPointX(x);
            setPointY(y);
            generatorRoom();
            a = true;
          }
        }
      }
    }
    rooms.push_back(GameRoom(getPointX(), getPointY()));
  }
  setDoorCoin();
}
// генератор комнат
void GameMap::generatorRoom() {
  GameRoom gameRoom = rooms.at(0);
  int random = std::experimental::randint(1, 100);
  // вверх
  if (random <= 25) setPointY(getPointY() - gameRoom.getRoomSizeY());
  // вниз
  if (random > 25 && random <= 50) setPointY(getPointY() + gameRoom.getRoomSizeY());
  // влево
  if (random > 50 && random <= 75) setPointX(getPointX() - gameRoom.getRoomSizeX());
  // вправо
  if (random > 75) setPointX(getPointX() + gameRoom.getRoomSizeX());
}
// генератор дверей
void GameMap::generatorDoor(int x, int y, int i) {
  for (unsigned int n = 0; n < rooms.size(); n++) {
    if (abs(abs(rooms.at(i).getY()) - abs(rooms.at(n).getY())) == rooms.at(0).getRoomSizeY() &&
        rooms.at(i).getX() == rooms.at(n).getX()) {
      // вверх
      if (rooms.at(i).getY() > rooms.at(n).getY()) rooms.at(i).doors[0] = true;
      // вниз
      if (rooms.at(i).getY() < rooms.at(n).getY()) rooms.at(i).doors[1] = true;
    }
    if (abs(abs(rooms.at(i).getX()) - abs(rooms.at(n).getX())) == rooms.at(0).getRoomSizeX() &&
        rooms.at(i).getY() == rooms.at(n).getY()) {
      // влево
      if (rooms.at(i).getX() > rooms.at(n).getX()) rooms.at(i).doors[2] = true;
      // вправо
      if (rooms.at(i).getX() < rooms.at(n).getX()) rooms.at(i).doors[3] = true;
    }
  }
}
// генератор монет
void GameMap::generatorCoin(int n) {
  for (int i = 0; i < std::experimental::randint(1, 4); i++) {
    rooms.at(n).pushCoin({std::experimental::randint(2, 29), std::experimental::randint(9, 18)});
  }
}
void GameMap::setDoorCoin() {
  for (unsigned int i = 0; i < rooms.size(); i++) {
    generatorDoor(rooms.at(i).getX(), rooms.at(i).getY(), i);
    generatorCoin(i);
  }
}
void GameMap::render(int n) {
  rooms.at(n).renderRoom();
  rooms.at(n).renderDoor();
}
void GameMap::renderCoin(int n) {
  rooms.at(n).renderCoin();
  rooms.at(n).renderExit();
}
void GameMap::scanner(int x, int y, int n) {
  for (int i = 0; i <= 3; i++) {
    if (sqrt(pow(rooms.at(n).doorsCoords[i][0] - x, 2) + pow(rooms.at(n).doorsCoords[i][1] - y, 2)) <= 1) {
      if (rooms.at(n).doors[i]) {
        teleport(i);
        playerPos(x, y, i);
        break;
      }
    }
  }
}
void GameMap::playerPos(int x, int y, int i) {
  player_x_ = x;
  player_y_ = y;
  if (i == 0) player_y_ += 15;
  if (i == 1) player_y_ -= 14;
  if (i == 2) player_x_ += 29;
  if (i == 3) player_x_ -= 29;
}
void GameMap::teleport(int i) {
  int buff_x = 0;
  int buff_y = 0;
  if (i == 0) buff_y -= rooms.at(0).getRoomSizeY();
  if (i == 1) buff_y += rooms.at(0).getRoomSizeY();
  if (i == 2) buff_x -= rooms.at(0).getRoomSizeX();
  if (i == 3) buff_x += rooms.at(0).getRoomSizeX();

  for (unsigned int n = 0; n < rooms.size(); n++) {
    if (rooms.at(number_room_).getX() + buff_x == rooms.at(n).getX()) {
      if (rooms.at(number_room_).getY() + buff_y == rooms.at(n).getY()) {
        number_room_ = n;
        render(n);
        break;
      }
    }
  }
}
int GameMap::getAllCoin() {
  int coin = 0;
  for (unsigned int i = 0; i < rooms.size(); i++) coin += rooms.at(i).getCoinCount();
  return coin;
}
GameRoom& GameMap::getCurrentRoom() {
  return rooms[number_room_];
}
int GameMap::getPointX() const {
  return point_x_;
}
void GameMap::setPointX(int pointX) {
  point_x_ = pointX;
}
int GameMap::getPointY() const {
  return point_y_;
}
void GameMap::setPointY(int pointY) {
  point_y_ = pointY;
}
int GameMap::getNumberRoom() const {
  return number_room_;
}
const std::vector<GameRoom>& GameMap::getRooms() const {
  return rooms;
}
void GameMap::setRooms(GameRoom gameRoom) {
  GameMap::rooms.push_back(GameRoom(gameRoom.getX(), gameRoom.getY()));
}

