#ifndef INCLUDE_GAME_MINIROOMS_H_
#define INCLUDE_GAME_MINIROOMS_H_

class MiniRooms {
 private:
  int x_;
  int y_;
  int symbol_mini_room = 0x4F;

 public:
  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  int getSymbolMiniRoom() const;
  MiniRooms(int x, int y);
};

#endif  // INCLUDE_GAME_MINIROOMS_H_
