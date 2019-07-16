#ifndef ROOMESCAPE_MAP_H
#define ROOMESCAPE_MAP_H

#include <vector>
#include "../include/room.h"

class Map {
private:
    std::vector<Room> rooms{{0, 0}};
    //точка первой комнаты
    int point_x_ = 0;
    int point_y_ = 0;
public:
    void generateRoom();
    void generateDoor(int x, int y, int i);
    void update();

    const int getPointX() const;
    const int getPointY() const;
    void setPointX(int pointX);
    void setPointY(int pointY);
};

#endif
