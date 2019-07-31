#ifndef INCLUDE_GAME_WALL_H_
#define INCLUDE_GAME_WALL_H_

class Wall {
 private:
  int symbol_wall_ = 0x23;

 public:
  int getSymbolWall() const;
};

#endif  // INCLUDE_GAME_WALL_H_
