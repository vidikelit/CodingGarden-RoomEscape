#ifndef ROOMESCAPE_GAMEINIT_H
#define ROOMESCAPE_GAMEINIT_H

#include "../include/player.h"
#include "../include/map.h"

class GameInit {
private:
    Map map;
    Controls &controls;
    Player player{controls, 11, 11};
public:
    void initialize();
    void update();

    GameInit(Controls &controls);
};


#endif
