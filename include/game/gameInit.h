#ifndef INCLUDE_GAME_GAMEINIT_H_
#define INCLUDE_GAME_GAMEINIT_H_

#include <vector>
#include "game/map.h"
#include "game/player.h"

class GameInit {
 private:
  Map map;
  Controls *controls;
  Player player{*controls, 11, 11};
  std::vector<const char*> menu{"Начало игры", "Выход"};
  bool gameStart_ = true;
  bool gameOver_ = false;
  bool coinStop_ = true;
  int menuPoint = 0;

 public:
  void initialize();
  void update();
  void renderHUD();
  void endGame();
  void gameStart();
  bool isCoinStop() const;
  void setCoinStop(bool coinStop);
  bool isGameStart() const;
  void setGameStart(bool gameStart);
  int getMenuPoint() const;
  void setMenuPoint(int menuPoint);
  explicit GameInit(Controls *controls);
};

#endif  // INCLUDE_GAME_GAMEINIT_H_
