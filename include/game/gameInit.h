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
  bool coinStop = true;
 public:
  void initialize();
  void update();
  void renderHUD();
  void endGame();
  bool isCoinStop() const;
  void setCoinStop(bool coinStop);

  explicit GameInit(Controls *controls);
};

#endif  // INCLUDE_GAME_GAMEINIT_H_
