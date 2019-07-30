#ifndef INCLUDE_GAME_GAMELOGIC_H_
#define INCLUDE_GAME_GAMELOGIC_H_

#include "game/controls.h"
#include "game/gameMenu.h"
#include "game/player.h"
#include "game/saver_loader.h"
#include "game/gameMap.h"
#include "game/miniMap.h"
#include "game/wall.h"

class GameLogic {
 private:
  GameMap gameMap;
  MiniMap miniMap;
  GameMenu gameMenu;
  SaverLoader saverLoader;
  Controls* controls;
  Player player{*controls, 11, 11};

  bool run_ = false;
  bool end_ = false;
  bool endGame_ = false;
  bool exitLevel_ = false;

 public:
  void newGame();
  void loadGame();
  void endGame();
  void update();
  void updateMenu();
  void initGame();
  void setSprites();
  void playerMove();
  void interWall(int x, int y);

  bool isRun() const;
  void setRun(bool run);
  bool isEnd() const;
  void setEnd(bool end);
  bool isExitLevel() const;
  void setExitLevel(bool exitLevel);

  explicit GameLogic(Controls* controls);
};

#endif  // INCLUDE_GAME_GAMELOGIC_H_
