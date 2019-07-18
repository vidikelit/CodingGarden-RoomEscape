#ifndef INC_ROOMESCAPE_PLAYER_H
#define INC_ROOMESCAPE_PLAYER_H

#include "controls.h"

class Player {
    private:
        const Controls &controls;
        const int symbol_ = 0x40;

        const int speed_ = 1;
        int coin = 0;
        int steps = 0;

        void render();
        void move();

    public:
        int x_;
        int y_;
        Player(const Controls &controls, int x, int y);

        void update();
        int getX() const;
        int getY() const;

    void setX(int x);

    void setY(int y);
};


#endif
