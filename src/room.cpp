#include <BearLibTerminal.h>
#include "../include/room.h"

Room::Room(int x, int y) : x_(x), y_(y) {

}

void Room::drawWall() {
    //отрисовка комнат карты
    for (int i = 0; i <= getRoomSize(); i++) {
        terminal_put(x_ + i, y_, symbol_wall_);
        terminal_put(x_ + i, y_ + getRoomSize(), symbol_wall_);
        terminal_put(x_, y_ + i, symbol_wall_);
        terminal_put(x_ + getRoomSize(), y_ + i, symbol_wall_);
    }
    //отрисовка комнат карты
//    for (int i = 0; i <= getRoomSize(); i++) {
//        terminal_put(i, 0, symbol_wall_);
//        terminal_put(i, getRoomSize(), symbol_wall_);
//        terminal_put(0, i, symbol_wall_);
//        terminal_put(getRoomSize(), i, symbol_wall_);
//    }
}

const int Room::getRoomSize() const {
    return room_size_;
}

int Room::getX() const {
    return x_;
}

void Room::setX(int x) {
    x_ = x;
}

int Room::getY() const {
    return y_;
}

void Room::setY(int y) {
    y_ = y;
}
