#ifndef ROOMESCAPE_DOOR_H
#define ROOMESCAPE_DOOR_H

#include "../include/controls.h"
#include "../include/player.h"
#include "../include/map.h"

class Door {
    private:
        Controls &controls;
        Player &player;
        void scanner();
        void teleport();

        const int doorsCoords[4][2] = {{9, 0}, {9, 21}, {0, 9}, {21, 9}};
    public:
    Door(Controls &controls, Player &player);
};


#endif
