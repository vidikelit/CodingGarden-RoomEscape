#ifndef INCLUDE_GAME_GAMELOGIC_H_
#define INCLUDE_GAME_GAMELOGIC_H_

#include "game/controls.h"
#include "game/gameMap.h"
#include "game/gameMenu.h"
#include "game/miniMap.h"
#include "game/player.h"
#include "game/saver_loader.h"

class GameLogic {
 private:
  GameMap gameMap;
  MiniMap miniMap;
  GameMenu gameMenu;
  SaverLoader saverLoader;
  Controls* controls;

  Player player{*controls, 10, 11};

  bool run_ = false;
  bool end_ = false;
  bool endGame_ = false;
  bool renderSave_ = false;
  bool exitLevel_ = false;

  int player_x_ = 0;
  int player_y_ = 0;

  int level_ = 0;
  bool loadLevel_ = false;

 public:
  void newGame();
  void loadGame();
  void newLevel();
  void saveLevel();
  void prevLevel();
  void endGame();
  void stats();
  void update();
  void updateMenu();
  void initGame();
  void setSprites();
  void playerMove();
  void interWall();
  void renderSave();

  // переход в новую комнату
  void scanner();
  void teleport();

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
  int getLevel() const;
  void setLevel(int level);

  explicit GameLogic(Controls* controls);
};

#endif  // INCLUDE_GAME_GAMELOGIC_H_
