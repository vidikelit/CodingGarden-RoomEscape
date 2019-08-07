#ifndef INCLUDE_GAME_ELEVATOR_H_
#define INCLUDE_GAME_ELEVATOR_H_

#include "game/lib/i_game_objects.h"

class Elevator : public IGameObjects {
 private:
  int x_ = 10;
  int y_ = 11;
  int symbol_evelator_ = 0x25;  // %
  bool exit_ = false;

 public:
  void update() override;
  void render() override;

  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  int getSymbolEvelator() const;
  bool isExit() const;
  void setExit(bool exit);
  Elevator(int x, int y);
  Elevator();
};

#endif  // INCLUDE_GAME_ELEVATOR_H_
