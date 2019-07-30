#ifndef INCLUDE_GAME_PLAYER_H_
#define INCLUDE_GAME_PLAYER_H_

#include "game/controls.h"
#include "game/gameMap.h"

class Player {
 private:
  const Controls &controls;
  int x_;
  int y_;
  int speed_ = 1;

  const int symbol_ = 0x40;

  int coin = 0;
  int steps = 0;

 public:
  Player(const Controls &controls, int x, int y);

  void update();
  void render();

  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  int getSteps() const;
  void setSteps(int steps);
  int getCoin() const;
  void setCoin(int coin);
  int getSpeed() const;
  void setSpeed(int speed);
};

#endif  // INCLUDE_GAME_PLAYER_H_
