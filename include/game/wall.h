#ifndef INCLUDE_GAME_WALL_H_
#define INCLUDE_GAME_WALL_H_

#include "game/lib/i_game_objects.h"

class Wall : public IGameObjects {
 private:
  int x_;
  int y_;
  int symbol_wall_ = 0x23;  // #

 public:
  void update() override;
  void render() override;
  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  int getSymbolWall() const;
};

#endif  // INCLUDE_GAME_WALL_H_
