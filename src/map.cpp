#include <BearLibTerminal.h>
#include "../include/map.h"

void Map::Draw() {
    //отрисовка комнат карты
    for(int i = 0; i <= getRoomSize(); i++) {
        terminal_put(point_x_ + i, point_y_, symbol_wall_);
        terminal_put(point_x_ + i, point_y_ + getRoomSize(), symbol_wall_);
        terminal_put(point_x_, point_y_ + i, symbol_wall_);
        terminal_put(point_x_ + getRoomSize(), point_y_ + i, symbol_wall_);
    }
}

void Map::Generate() {
    int random = rand() % 100 + 1;
    //вверх
    if(random <= 25)
        setPointY(getPointY() - (getRoomSize()));
    //вниз
    if(random > 25 && random <= 50)
        setPointY(getPointY() + (getRoomSize()));
    //влево
    if(random > 50 && random <= 75)
        setPointX(getPointX() - (getRoomSize()));
    //вправо
    if(random > 75)
        setPointX(getPointX() + (getRoomSize()));
}

void Map::Update(){
    int random = rand() % 10 + 5;
    for(int i = 0; i <= random; i++){
        int x = getPointX();
        int y = getPointY();
        Generate();
        while(terminal_pick(getPointX()+1, getPointY()+1, 0) == symbol_wall_){
            setPointX(x);
            setPointY(y);
            Generate();
        }
        Draw();
    }
}

const int Map::getRoomSize() const {
    return room_size_;
}

const int Map::getPointX() const {
    return point_x_;
}

const int Map::getPointY() const {
    return point_y_;
}

void Map::setPointX(int pointX) {
    point_x_ = pointX;
}

void Map::setPointY(int pointY) {
    point_y_ = pointY;
}
