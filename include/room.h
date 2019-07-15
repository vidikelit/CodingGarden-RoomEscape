#ifndef ROOMESCAPE_ROOM_H
#define ROOMESCAPE_ROOM_H


class Room {
    public:
        int x_;
        int y_;
        //размер комнаты
        const int room_size_ = 2;
        const int symbol_wall_ = 0x23;

        void drawWall();
        Room(int x, int y);
        const int getRoomSize() const;

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);
};


#endif
