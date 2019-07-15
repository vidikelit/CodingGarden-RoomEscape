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

void Map::Door(int x1, int y1) {
    //вверх
    if (y1 > getPointY())
        drawDoor(x1 + 1, y1);
    //вниз
    if (y1 < getPointY())
        drawDoor(getPointX() + 1, getPointY());
    //влево
    if (x1 > getPointX())
        drawDoor(x1, y1 + 1);
    //вправо
    if (x1 < getPointX())
        drawDoor(getPointX(), getPointY() + 1);
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
