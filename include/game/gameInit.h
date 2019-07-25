#ifndef INCLUDE_GAME_GAMEINIT_H_
#define INCLUDE_GAME_GAMEINIT_H_

#include <vector>
#include "game/map.h"
#include "game/player.h"
#include "game/saver_loader.h"

class GameInit {
 private:
  Map map;
  SaverLoader saverLoader;
  Controls* controls;
  Player player{*controls, 11, 11};
  const char* new_game_ = "Новая игра";
  const char* end_game_ = "Выход";
  const char* continue_game_ = "Продолжить";
  const char* save_game_ = "Сохранить";
  const char* load_game_ = "Загрузить";

  const char* slot1_ = "Слот 1";
  const char* slot2_ = "Слот 2";
  const char* slot3_ = "Слот 3";

  std::vector<const char*> menu{new_game_, load_game_, end_game_};
  std::vector<const char*> menuLoad{slot1_, slot2_, slot3_};
  bool gameStart_ = true;
  bool gameOver_ = false;

 private:
  bool coinStop_ = true;

  int menuPoint = 0;
  int menuStatus = 0;

 public:
  int getMenuStatus() const;
  void setMenuStatus(int menuStatus);

 public:
  bool isGameOver() const;
  void initializeNew();
  void initializeLoad();
  void update();
  void renderHUD();
  void endGame();
  void setSprites();
  void setMenu();

  void gameMenu();
  void loadMenu();
  void saveMenu();

  bool isCoinStop() const;
  void setCoinStop(bool coinStop);
  bool isGameStart() const;
  void setGameStart(bool gameStart);
  int getMenuPoint() const;
  void setMenuPoint(int menuPoint);
  explicit GameInit(Controls* controls);
};

#endif  // INCLUDE_GAME_GAMEINIT_H_
