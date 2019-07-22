#include <BearLibTerminal.h>
#include "game/controls.h"
#include "game/gameInit.h"
#include "game/map.h"
#include "game/player.h"
#include "game/window.h"

int main() {
  Window window;

  terminal_open();
  terminal_composition(TK_ON);
  window.Settings();
  terminal_refresh();
  Controls controls;
  GameInit gameInit(&controls);
  while (true) {
    controls.Update();
    if (gameInit.isGameStart()) {
      gameInit.gameMenu();
      if (gameInit.getMenuPoint() == 11) break;
    } else {
      gameInit.update();
    }
    if (controls.isExit()) break;
    terminal_refresh();
  }
  gameInit.endGame();
  terminal_close();
}
