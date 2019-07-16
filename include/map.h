#ifndef ROOMESCAPE_MAP_H
#define ROOMESCAPE_MAP_H

#include "../include/room.h"
#include <vector>

class Map {
private:
    std::vector<Room> rooms{{0, 0}};

    int point_x_ = 0;
    int point_y_ = 0;
public:
    int number_room_ = 0;
    void generateRoom();
    void generateDoor(int x, int y, int i);
    void generator();
    void update();
    void render(int n);
    void scanner(int x_p, int y_p, int n_r);
    void teleport(int i);

    const int getPointX() const;
    const int getPointY() const;
    void setPointX(int pointX);
    void setPointY(int pointY);
};

#endif
