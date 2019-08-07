#ifndef INCLUDE_GAME_DOOR_H_
#define INCLUDE_GAME_DOOR_H_

#include "game/lib/i_game_objects.h"

class Door : public IGameObjects {
 private:
  int x_;
  int y_;
  int symbol_door_ = 0x3E;  // >

 public:
  void update() override;
  void render() override;

  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  int getSymbolDoor() const;
  Door(int x, int y);
  Door();
};

#endif  // INCLUDE_GAME_DOOR_H_
