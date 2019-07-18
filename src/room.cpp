#include <BearLibTerminal.h>
#include "../include/room.h"

Room::Room(int x, int y) : x_(x), y_(y) {}

void Room::renderRoom(){
    //отрисовка стен комнаты
    for(int i = 0; i <= getRoomSize(); i++) {
        terminal_put(i, 0, symbol_wall_);
        terminal_put(i, getRoomSize(), symbol_wall_);
        terminal_put(0, i, symbol_wall_);
        terminal_put(getRoomSize(), i, symbol_wall_);
    }
//    //отрисовка пола
//    for(int i = 1; i < getRoomSize(); i++) {
//        for (int j = 1; j < getRoomSize(); j++) {
//            terminal_put(i, j, 0xB7);
//        }
//    }
}

void Room::renderDoor() {
    //отрисовка дверей
    for(int i = 0; i <= 4; i++){
        if(doors[i] == true){
            terminal_put(doorsCoords[i][0], doorsCoords[i][1], symbol_door_);
        }
    }
}

void Room::renderCoin() {
    terminal_clear_area(1, 1, 19, 19);
    for(auto &coin:coins){
        terminal_put(coin.getX(), coin.getY(), coin.getSymbolCoin());
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

