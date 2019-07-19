#ifndef INCLUDE_GAME_CONTROLS_H_
#define INCLUDE_GAME_CONTROLS_H_

class Controls {
 private:
  bool is_up_;
  bool is_down_;
  bool is_right_;
  bool is_left_;
  bool is_e;
  bool is_enter_;
  bool is_exit_;

 public:
  bool isUp() const;
  bool isDown() const;
  bool isRight() const;
  bool isLeft() const;
  bool isExit() const;
  bool isE() const;
  bool isEnter() const;

  void Update();
};

#endif  // INCLUDE_GAME_CONTROLS_H_
