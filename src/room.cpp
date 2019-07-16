#include <BearLibTerminal.h>
#include "../include/room.h"

Room::Room(int x, int y) : x_(x), y_(y) {}

void Room::drawRoom() {
//    отрисовка комнат карты
    for (int i = 0; i <= getRoomSize(); i++) {
        terminal_put(x_ + i, y_, symbol_wall_);
        terminal_put(x_ + i, y_ + getRoomSize(), symbol_wall_);
        terminal_put(x_, y_ + i, symbol_wall_);
        terminal_put(x_ + getRoomSize(), y_ + i, symbol_wall_);
    }
//    пол
    for(int i = 1; i < getRoomSize(); i++){
        for(int j = 1; j < getRoomSize(); j++){
            terminal_put(i, j, 0xB7);
        }
    }
}

const int Room::getRoomSize() const {
    return room_size_;
}

int Room::getX() const {
    return x_;
}

int Room::getY() const {
    return y_;
}
