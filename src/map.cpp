#include <BearLibTerminal.h>
#include <vector>
#include "../include/map.h"
#include "../include/room.h"

void Map::drawDoor(int x, int y) {
    terminal_put(x, y, 0x3E);
}

void Map::Generate() {
    Room room = rooms.at(0);
    int random = rand() % 100 + 1;
    //вверх
    if (random <= 25)
        setPointY(getPointY() - room.getRoomSize());
    //вниз
    if (random > 25 && random <= 50)
        setPointY(getPointY() + room.getRoomSize());
    //влево
    if (random > 50 && random <= 75)
        setPointX(getPointX() - room.getRoomSize());
    //вправо
    if (random > 75)
        setPointX(getPointX() + room.getRoomSize());
}

void Map::Door(int x, int y) {
    Room room = rooms.at(0);
    //вверх
    if(terminal_pick(x + 1, y - 1, 0) == 0xB7){
        terminal_put(x + 1, y, 0x3E);
    }
    //вниз
    if(terminal_pick(x + 1, y + room.getRoomSize() + 1, 0) == 0xB7){
        terminal_put(x + 1, y + room.getRoomSize(), 0x3E);
    }
    //влево
    if(terminal_pick(x - 1, y + 1, 0) == 0xB7){
        terminal_put(x, y + 1, 0x3E);
    }
    //вправо
    if(terminal_pick(x + room.getRoomSize() + 1, y + 1, 0) == 0xB7){
        terminal_put(x + room.getRoomSize(), y + 1, 0x3E);
    }
}

void Map::Update() {
    int random = 5 + rand() % 10;
    for(int i = 0; i <= random; i++) {
        bool a = true;
        int x = getPointX();
        int y = getPointY();
        Generate();
        while(a){
            a = false;
            for(int i = 0; i < rooms.size(); i++){
                if(rooms.at(i).getX() == getPointX()){
                    if(rooms.at(i).getY() == getPointY()){
                        setPointX(x);
                        setPointY(y);
                        Generate();
                        a = true;
                    }

                }
            }
        }
        rooms.push_back(Room(getPointX(), getPointY()));
        rooms.at(i).drawWall();
    }
    rooms.at(rooms.size()-1).drawWall();
    for(int i = 0; i < rooms.size(); i++){
        Door(rooms.at(i).getX(), rooms.at(i).getY());
    }
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
