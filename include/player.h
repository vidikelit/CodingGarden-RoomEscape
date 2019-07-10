#ifndef INC_ROOMESCAPE_PLAYER_H
#define INC_ROOMESCAPE_PLAYER_H

#include "controls.h"

class Player {
    private:
        const Controls &controls;
        int symbol_ = 0xE64;

        const int speed_ = 1;
        int x_;
        int y_;

        void Render();
        void Move();

    public:
        Player(const Controls &controls, int x, int y);

    void Update();

        int GetX() const;
        int GetY() const;
};


#endif
