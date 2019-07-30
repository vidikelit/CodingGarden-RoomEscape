#include "game/miniRooms.h"

void MiniRooms::moveRoom(int i) {
//  // вверх
//  if (i == 0) {
//    for (unsigned int j = 0; j < miniRooms.size(); j++) {
//      miniRooms.at(j).setY(miniRooms.at(j).getY() + 1);
//    }
//  }
//  // вниз
//  if (i == 1) {
//    for (unsigned int j = 0; j < miniRooms.size(); j++) {
//      miniRooms.at(j).setY(miniRooms.at(j).getY() - 1);
//    }
//  }
//  // влево
//  if (i == 2) {
//    for (unsigned int j = 0; j < miniRooms.size(); j++) {
//      miniRooms.at(j).setX(miniRooms.at(j).getX() + 1);
//    }
//  }
//  // вправо
//  if (i == 3) {
//    for (unsigned int j = 0; j < miniRooms.size(); j++) {
//      miniRooms.at(j).setX(miniRooms.at(j).getX() - 1);
//    }
//  }
}
int MiniRooms::getX() const {
  return x_;
}
void MiniRooms::setX(int x) {
  x_ = x;
}
int MiniRooms::getY() const {
  return y_;
}
void MiniRooms::setY(int y) {
  y_ = y;
}
MiniRooms::MiniRooms(int x, int y) : x_(x), y_(y) {}
