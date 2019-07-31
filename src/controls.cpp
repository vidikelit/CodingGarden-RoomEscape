#include "game/controls.h"
#include <BearLibTerminal.h>

void Controls::Update() {
  is_up_ = false;
  is_down_ = false;
  is_right_ = false;
  is_left_ = false;
  is_e_ = false;
  is_exit_ = false;
  is_enter_ = false;
  is_esc_ = false;

  while (terminal_has_input()) {
    auto key = terminal_read();
    // вверх стрелочка или W
    if (key == TK_UP || key == TK_W) is_up_ = true;
    // вниз стрелочка или S
    if (key == TK_DOWN || key == TK_S) is_down_ = true;
    // влево стрелочка или A
    if (key == TK_LEFT || key == TK_A) is_left_ = true;
    // вправо стрелочка или D
    if (key == TK_RIGHT || key == TK_D) is_right_ = true;
    // закрытие окна
    if (key == TK_CLOSE) is_exit_ = true;
    // взаимодействие с объектами (дверь) E
    if (key == (TK_E | TK_KEY_RELEASED)) is_e_ = true;
    // выбор
    if (key == (TK_ENTER| TK_KEY_RELEASED) is_enter_ = true;
    // выход в меню
    if (key == TK_ESCAPE) is_esc_ = true;
  }
}

bool Controls::isUp() const {
  return is_up_;
}
bool Controls::isDown() const {
  return is_down_;
}
bool Controls::isRight() const {
  return is_right_;
}
bool Controls::isLeft() const {
  return is_left_;
}
bool Controls::isExit() const {
  return is_exit_;
}
bool Controls::isE() const {
  return is_e_;
}
bool Controls::isEnter() const {
  return is_enter_;
}
bool Controls::isEsc() const {
  return is_esc_;
}
