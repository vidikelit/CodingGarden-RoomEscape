#ifndef INCLUDE_GAME_PLAYER_H_
#define INCLUDE_GAME_PLAYER_H_

#include "game/controls.h"
#include "game/gameMap.h"

class Player {
 private:
  const Controls &controls;
  int x_;
  int y_;

  const int symbol_ = 0x40;

  const int speed_ = 1;
  int coin = 0;
  int steps = 0;

 public:
  Player(const Controls &controls, int x, int y);

  void update();
  void render();
  void move();
  void restriction();

  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  int getSteps() const;
  void setSteps(int steps);
  int getCoin() const;
  void setCoin(int coin);
};

#endif  // INCLUDE_GAME_PLAYER_H_
