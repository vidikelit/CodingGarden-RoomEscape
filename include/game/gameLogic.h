#ifndef INCLUDE_GAME_GAMELOGIC_H_
#define INCLUDE_GAME_GAMELOGIC_H_

#include "game/controls.h"
#include "game/gameMenu.h"
#include "game/map.h"
#include "game/player.h"
#include "game/saver_loader.h"

class GameLogic {
 private:
  Map map;
  GameMenu gameMenu;
  SaverLoader saverLoader;
  Controls* controls;
  Player player{*controls, 11, 11};

  bool run_ = false;
  bool end_ = false;
  bool endGame_ = false;

 public:
  void newGame();
  void loadGame();
  void endGame();
  void update();
  void updateMenu();
  void initGame();
  void setSprites();

  bool isRun() const;
  void setRun(bool run);
  bool isEnd() const;
  void setEnd(bool end);
  explicit GameLogic(Controls* controls);
};

#endif  // INCLUDE_GAME_GAMELOGIC_H_
