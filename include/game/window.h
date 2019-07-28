#ifndef INCLUDE_GAME_WINDOW_H_
#define INCLUDE_GAME_WINDOW_H_

class Window {
 private:
  const char* title_ = "RoomEscape";
  const char icon_ = '-';
  // размер окна
  int window_x_ = 21;
  int window_y_ = 17;
  bool fullscreen_ = true;

 public:
  void Settings();
  int getWindowX() const;
  int getWindowY() const;
};

#endif  // INCLUDE_GAME_WINDOW_H_
