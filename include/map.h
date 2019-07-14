#ifndef ROOMESCAPE_MAP_H
#define ROOMESCAPE_MAP_H


class Map {
private:
    const int symbol_wall_ = 0x23;
    const int room_size_ = 3;
    int point_x_ = 12;
    int point_y_ = 10;
public:
    void Draw();
    void Generate();
    void Update();

    const int getRoomSize() const;

    const int getPointX() const;

    const int getPointY() const;

    void setPointX(int pointX);

    void setPointY(int pointY);
};

#endif
