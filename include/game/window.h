#ifndef INCLUDE_GAME_WINDOW_H_
#define INCLUDE_GAME_WINDOW_H_

class Window {
 private:
  const char* title_ = "RoomEscape";
  const char icon_ = '-';
  // размер для 16:9
  int window_x_ = 28;
  int window_y_ = 21;
  bool fullscreen_ = false;

 public:
  void Settings();
};

#endif  // INCLUDE_GAME_WINDOW_H_
