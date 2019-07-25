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
  terminal_set("input: filter=[keyboard+];");
  GameInit gameInit(&controls);
  while (true) {
    controls.Update();
    if (gameInit.isGameStart()) {
      if (gameInit.getMenuPoint() == 11) break;
      if (gameInit.getMenuStatus() == 1 || gameInit.getMenuStatus() == 2) {
        if (gameInit.getMenuStatus() == 1) gameInit.loadMenu();
        if (gameInit.getMenuStatus() == 2) gameInit.saveMenu();
      } else {
        gameInit.gameMenu();
      }
    } else {
      gameInit.update();
    }
    if (controls.isExit()) break;
    terminal_refresh();
  }
  terminal_close();
}
