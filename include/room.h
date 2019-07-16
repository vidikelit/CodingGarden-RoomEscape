#ifndef ROOMESCAPE_ROOM_H
#define ROOMESCAPE_ROOM_H


class Room {
    private:
        int x_;
        int y_;
        //размер комнаты
        const int room_size_ = 20;
        const int symbol_wall_ = 0x23;
        const int symbol_door_ = 0xB7;
    public:
        bool doors[4] = {false, false, false, false};

        void drawRoom();

        Room(int x, int y);

        const int getRoomSize() const;
        int getX() const;
        int getY() const;
};


#endif
