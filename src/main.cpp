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
    controls.Update();
    gameInit.update();
    if (controls.isExit()) break;
    terminal_refresh();
  }
  terminal_close();
}
