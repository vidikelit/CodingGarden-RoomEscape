#ifndef INCLUDE_GAME_MINIROOMS_H_
#define INCLUDE_GAME_MINIROOMS_H_

class MiniRooms {
 private:
  int x_;
  int y_;

 public:
  void render();
  void moveRoom(int i);

  int getX() const;
  void setX(int x);
  int getY() const;
  void setY(int y);
  MiniRooms(int x, int y);
};

#endif  // INCLUDE_GAME_MINIROOMS_H_
