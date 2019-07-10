#include <BearLibTerminal.h>
#include "../include/window.h"

void Window::Settings() {
    terminal_setf("window: cellsize=48x48, title='%s', size=%dx%d, icon=%d, fullscreen=%d",
            title_, window_x_, window_y_, icon_, fullscreen_);
}
