#ifndef ROOMESCAPE_ROOM_H
#define ROOMESCAPE_ROOM_H

#include <vector>
#include "coin.h"

class Room {
    private:
        int x_;
        int y_;
        //размер комнаты
        const int room_size_ = 20;
        const int symbol_wall_ = 0x23;
        const int symbol_door_ = 0x3E;
    public:
        std::vector<Coin> coins{};
        const int doorsCoords[4][2] = {{10, 0}, {10, 20}, {0, 10}, {20, 10}};
        bool doors[4] = {false, false, false, false};

        void renderRoom();
        void renderDoor();
        void renderCoin();

        Room(int x, int y);

        const int getRoomSize() const;
        int getX() const;
        int getY() const;
};


#endif
