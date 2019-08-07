#include <BearLibTerminal.h>
#include "game/controls.h"
#include "game/gameLogic.h"
#include "game/player.h"
#include "game/window.h"

#include "game/gameMap.h"

int main() {
  Window window;
  Controls controls;
  GameLogic gameLogic(&controls);

  terminal_open();
  terminal_refresh();
  terminal_composition(TK_ON);
  terminal_set("input: filter=[keyboard+];");
  window.Settings();
  gameLogic.initGame();
  while (true) {
    controls.Update();
    if (gameLogic.isEnd()) break;
    if (gameLogic.isRun()) {
      gameLogic.update();
    } else {
      gameLogic.updateMenu();
    }
    terminal_refresh();
  }
  terminal_close();
}
