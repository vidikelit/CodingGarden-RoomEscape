#ifndef INCLUDE_GAME_ENEMY_H_
#define INCLUDE_GAME_ENEMY_H_

#include "game/lib/i_game_objects.h"

class Enemy : public IGameObjects {
 private:
  int x_;
  int y_;
  int symbol_enemy_ = 0x2A;  // *

  int speed_ = 1;
  int health = 100;

 public:
  void update() override;
  void render() override;
};

#endif  // INCLUDE_GAME_ENEMY_H_
