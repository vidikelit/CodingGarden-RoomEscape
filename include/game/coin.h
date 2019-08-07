#ifndef INCLUDE_GAME_COIN_H_
#define INCLUDE_GAME_COIN_H_

#include "game/lib/i_game_objects.h"

class Coin : public IGameObjects {
 private:
  int x_;
  int y_;
  int symbol_coin_ = 0x24;  // $

 public:
  void update() override;
  void render() override;

  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  int getSymbolCoin() const;
  Coin(int x, int y);
};

#endif  // INCLUDE_GAME_COIN_H_
