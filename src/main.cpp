#include <BearLibTerminal.h>
#include "game/controls.h"
#include "game/gameInit.h"
#include "game/map.h"
#include "game/player.h"
#include "game/window.h"

int main() {
  srand(time(NULL));
  Window window;
  terminal_open();
  window.Settings();
  terminal_refresh();
  Controls controls;
  GameInit gameInit(&controls);
  gameInit.initialize();
  while (true) {
    terminal_layer(1);
    terminal_clear_area(1, 1, 19, 19);
    terminal_layer(0);
    terminal_clear_area(1, 1, 19, 19);

    controls.Update();
    gameInit.update();

    if (controls.isExit()) break;
    terminal_refresh();
  }
  terminal_close();
}
