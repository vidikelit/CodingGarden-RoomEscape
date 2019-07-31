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
  bool renderSave_ = false;
  bool exitLevel_ = false;

  int player_x_ = 0;
  int player_y_ = 0;

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
  void renderSave();
  void stats();

  // переход в новую комнату
  void scanner(int x, int y, int n);
  void playerPos(int x, int y, int n);
  void teleport(int i);

  bool isRun() const;
  void setRun(bool run);
  bool isEnd() const;
  void setEnd(bool end);
  bool isExitLevel() const;
  void setExitLevel(bool exitLevel);
  int getPlayerX() const;
  void setPlayerX(int playerX);
  int getPlayerY() const;
  void setPlayerY(int playerY);
  bool isEndGame() const;
  void setEndGame(bool endGame);
  explicit GameLogic(Controls* controls);
};

#endif  // INCLUDE_GAME_GAMELOGIC_H_
