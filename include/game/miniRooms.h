#ifndef INCLUDE_GAME_MINIROOMS_H_
#define INCLUDE_GAME_MINIROOMS_H_

class MiniRooms {
 private:
  int x_;
  int y_;
  int symbol_mini_room_ = 0x2B;
  int pos_render_x_ = 2;
  int pos_render_y_ = 2;

 public:
  void render();

  int getX() const;
  int getY() const;
  void setX(int x);
  void setY(int y);
  int getPosRenderX() const;
  int getPosRenderY() const;
  int getSymbolMiniRoom() const;
  MiniRooms(int x, int y);
};

#endif  // INCLUDE_GAME_MINIROOMS_H_
