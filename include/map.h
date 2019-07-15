#ifndef ROOMESCAPE_MAP_H
#define ROOMESCAPE_MAP_H

#include <vector>
#include "../include/room.h"

class Map {
private:
    std::vector<Room> rooms{{10, 10}};
    //точка первой комнаты
    int point_x_ = 10;
    int point_y_ = 10;
public:
    void drawDoor(int x, int y);
    void Generate();
    void Door(int x, int y);
    void Update();

    const int getPointX() const;

    const int getPointY() const;

    void setPointX(int pointX);

    void setPointY(int pointY);
};

#endif
