#ifndef INCLUDE_GAME_GAMEINIT_H_
#define INCLUDE_GAME_GAMEINIT_H_

#include "game/map.h"
#include "game/player.h"

class GameInit {
 private:
  Map map;
  Controls *controls;
  Player player{*controls, 11, 11};

  bool gameOver = false;
 public:
  void initialize();
  void update();
  void renderHUD();

  void endGame();

  explicit GameInit(Controls *controls);
};

#endif  // INCLUDE_GAME_GAMEINIT_H_
