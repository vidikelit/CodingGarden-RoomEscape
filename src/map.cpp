#include <BearLibTerminal.h>
#include <vector>
#include <tgmath.h>
#include "../include/map.h"
#include "../include/room.h"
#include "../include/controls.h"
#include "../include/player.h"

void Map::generateRoom() {
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

void Map::generateDoor(int x, int y, int i) {
    for (int n = 0; n < rooms.size(); n++) {
        if (abs(abs(rooms.at(i).getY()) - abs(rooms.at(n).getY())) == 20 && rooms.at(i).getX() == rooms.at(n).getX()) {
            if (rooms.at(i).getY() > rooms.at(n).getY())
                //вверх
                rooms.at(i).doors[0] = true;
            if (rooms.at(i).getY() < rooms.at(n).getY())
                //вниз
                rooms.at(i).doors[1] = true;
        }
        if (abs(abs(rooms.at(i).getX()) - abs(rooms.at(n).getX())) == 20 && rooms.at(i).getY() == rooms.at(n).getY()) {
            if (rooms.at(i).getX() > rooms.at(n).getX())
                //влево
                rooms.at(i).doors[2] = true;
            if (rooms.at(i).getX() < rooms.at(n).getX())
                //вправо
                rooms.at(i).doors[3] = true;
        }
    }
}

void Map::generateCoin(int n) {
    for(int i = 0; i <= 2 + rand() % 2; i++) {
        rooms.at(n).coins.push_back({4 + rand() % 16, 4 + rand() % 16});
    }
}

void Map::generator() {
    int random = 5 + rand() % 5;
    for (int i = 0; i <= random; i++) {
        bool a = true;
        int x = getPointX();
        int y = getPointY();
        generateRoom();
        while (a) {
            a = false;
            for (int i = 0; i < rooms.size(); i++) {
                if (rooms.at(i).getX() == getPointX()) {
                    if (rooms.at(i).getY() == getPointY()) {
                        setPointX(x);
                        setPointY(y);
                        generateRoom();
                        a = true;
                    }

                }
            }
        }
        rooms.push_back(Room(getPointX(), getPointY()));
    }
    for (int i = 0; i < rooms.size(); i++) {
        generateDoor(rooms.at(i).getX(), rooms.at(i).getY(), i);
        generateCoin(i);
    }
}

void Map::render(int n) {
//    terminal_set("0x23: ../src/tiles/castle.png");
//    terminal_set("0x3E: ../src/tiles/door.png");
//    terminal_set("0x24: ../src/tiles/coinGold.png");
    rooms.at(n).renderRoom();
    rooms.at(n).renderDoor();
    rooms.at(n).renderCoin();
}

void Map::scanner(int x, int y, int n) {
    for (int i = 0; i <= 3; i++) {
        if (sqrt(pow(rooms.at(n).doorsCoords[i][0] - x, 2) + pow(rooms.at(n).doorsCoords[i][1] - y, 2)) <= 1) {
            if (rooms.at(n).doors[i] == true) {
                teleport(i);
                playerPos(x, y, i);
                break;
            }
        }
    }
}

void Map::playerPos(int x, int y, int i) {
    player_x = x;
    player_y = y;
    if (i == 0)
        player_y += 19;
    if (i == 1)
        player_y -= 19;
    if (i == 2)
        player_x += 19;
    if (i == 3)
        player_x -= 19;
}

void Map::teleport(int i) {
    int buff_x = 0;
    int buff_y = 0;
    if (i == 0)
        buff_y -= rooms.at(0).getRoomSize();
    if (i == 1)
        buff_y += rooms.at(0).getRoomSize();
    if (i == 2)
        buff_x -= rooms.at(0).getRoomSize();
    if (i == 3)
        buff_x += rooms.at(0).getRoomSize();

    for (int n = 0; n < rooms.size(); n++) {
        if (rooms.at(number_room_).getX() + buff_x == rooms.at(n).getX()) {
            if (rooms.at(number_room_).getY() + buff_y == rooms.at(n).getY()) {
                number_room_ = n;
                render(n);
                break;
            }
        }
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


