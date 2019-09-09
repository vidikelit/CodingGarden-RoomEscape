#include "game/window.h"
#include <BearLibTerminal.h>

void Window::Settings() {
  terminal_setf("window: cellsize=64x64, title='%s', size=%dx%d, icon=%d, fullscreen=%d", title_, window_x_, window_y_,
                icon_, fullscreen_);
  terminal_set("font: ../resources/fonts/RussoOne-Regular.ttf, size=48");
}
int Window::getWindowX() const {
  return window_x_;
}
int Window::getWindowY() const {
  return window_y_;
}
