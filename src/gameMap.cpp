#include "game/gameMap.h"
#include <experimental/random>
#include <vector>
#include "game/player.h"

void GameMap::update() {
  generatorLevel();
  for (unsigned int n_room = 0; n_room < rooms.size(); n_room++) {
    generatorDoor(n_room);
    generatorCoin(n_room);
  }
}
void GameMap::updateDoor() {
  for (unsigned int n_room = 0; n_room < rooms.size(); n_room++) generatorDoor(n_room);
}
// генерирование комнат
void GameMap::generatorLevel() {
  for (int i = 0; i < std::experimental::randint(minRooms, maxRooms); i++) {
    int x = getX();
    int y = getY();
    generatorRoom();
    bool a = true;
    while (a) {
      a = false;
      for (unsigned int i = 0; i < rooms.size(); i++) {
        if (rooms.at(i).getX() == getX()) {
          if (rooms.at(i).getY() == getY()) {
            setX(x);
            setY(y);
            generatorRoom();
            a = true;
          }
        }
      }
    }
    rooms.push_back(GameRoom(getX(), getY()));
  }
}
// генератор координат комнат
void GameMap::generatorRoom() {
  GameRoom gameRoom = rooms.at(0);
  int random = std::experimental::randint(1, 100);
  // вверх
  if (random <= 25) setY(getY() - gameRoom.getRoomSizeY());
  // вниз
  if (random > 25 && random <= 50) setY(getY() + gameRoom.getRoomSizeY());
  // влево
  if (random > 50 && random <= 75) setX(getX() - gameRoom.getRoomSizeX());
  // вправо
  if (random > 75) setX(getX() + gameRoom.getRoomSizeX());
}
// генератор координат дверей
void GameMap::generatorDoor(int n_room) {
  for (unsigned int n = 0; n < rooms.size(); n++) {
    if (abs(abs(rooms.at(n_room).getY()) - abs(rooms.at(n).getY())) == rooms.at(0).getRoomSizeY() &&
        rooms.at(n_room).getX() == rooms.at(n).getX()) {
      // вверх
      if (rooms.at(n_room).getY() > rooms.at(n).getY()) rooms.at(n_room).setDoorCoord(10, 6);
      // вниз
      if (rooms.at(n_room).getY() < rooms.at(n).getY()) rooms.at(n_room).setDoorCoord(10, 16);
    }
    if (abs(abs(rooms.at(n_room).getX()) - abs(rooms.at(n).getX())) == rooms.at(0).getRoomSizeX() &&
        rooms.at(n_room).getY() == rooms.at(n).getY()) {
      // влево
      if (rooms.at(n_room).getX() > rooms.at(n).getX()) rooms.at(n_room).setDoorCoord(0, 11);
      // вправо
      if (rooms.at(n_room).getX() < rooms.at(n).getX()) rooms.at(n_room).setDoorCoord(20, 11);
    }
  }
}
// генератор координат монет
void GameMap::generatorCoin(int n_room) {
  for (int i = 0; i < std::experimental::randint(1, 4); i++) {
    rooms.at(n_room).setCoinCoord(std::experimental::randint(3, 16), std::experimental::randint(9, 14));
  }
}
void GameMap::formRoom(int x, int y) {
  rooms.push_back(GameRoom(x, y));
}
void GameMap::formCoin(int x, int y, int r) {
  rooms.at(r).getCoins().push_back(Coin(x, y));
}
void GameMap::setTilesRooms(bool tile) {
  for (unsigned int i = 0; i < rooms.size(); i++) rooms.at(i).setTiles(tile);
}
int GameMap::getAllCoin() {
  int coin = 0;
  for (unsigned int i = 0; i < rooms.size(); i++) coin += rooms.at(i).getCoinCount();
  return coin;
}
GameRoom& GameMap::getCurrentRoom() {
  return rooms[number_room_];
}
std::vector<GameRoom>& GameMap::getRooms() {
  return rooms;
}
int GameMap::getX() const {
  return x_;
}
void GameMap::setX(int x) {
  x_ = x;
}
int GameMap::getY() const {
  return y_;
}
void GameMap::setY(int y) {
  y_ = y;
}
int GameMap::getNumberRoom() const {
  return number_room_;
}
void GameMap::setNumberRoom(int numberRoom) {
  number_room_ = numberRoom;
}
