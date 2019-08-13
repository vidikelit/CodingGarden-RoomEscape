#ifndef INCLUDE_GAME_PLAYER_H_
#define INCLUDE_GAME_PLAYER_H_

#include "game/controls.h"
#include "game/gameMap.h"
#include "game/lib/i_game_objects.h"

class Player : public IGameObjects {
 private:
  const Controls &controls;
  int x_;
  int y_;
  int symbol_player_ = 0x40;  // @

  int speed_ = 1;
  int health = 100;
  int coin_ = 0;
  int steps_ = 0;

 public:
  void update() override;
  void render() override;
  void setDefault();

  int addStep();
  int removeStep();
  int addCoin();
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  int getSpeed() const;
  int getSteps() const;
  void setCoin(int coin);
  int getCoin() const;
  void setSteps(int steps);
  Player(const Controls &controls, int x, int y);
};

#endif  // INCLUDE_GAME_PLAYER_H_
