#ifndef ROOMESCAPE_COIN_H
#define ROOMESCAPE_COIN_H

class Coin {
    private:
        int x_;
        int y_;
        int symbol_coin_ = 0x24;
    public:
        Coin(int x, int y);

        int getX() const;
        int getY() const;
        void setX(int x);
        void setY(int y);

        const int getSymbolCoin() const;
};


#endif
