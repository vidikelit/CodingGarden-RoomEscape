#ifndef INCLUDE_GAME_GAMEINIT_H_
#define INCLUDE_GAME_GAMEINIT_H_

#include <vector>
#include "game/map.h"
#include "game/player.h"

class GameInit {
 private:
  Map map;
  Controls* controls;
  Player player{*controls, 11, 11};
  const char* new_game_ = "Новая игра";
  const char* end_game_ = "Выход";
  const char* continue_game_ = "Продолжить";
  const char* save_game_ = "Сохранить";
  const char* load_game_ = "Загрузить";

  std::vector<const char*> menu{new_game_, load_game_, end_game_};
  std::vector<const char*> menuLoad{"Слот 1", "Слот 2", "Слот 3", "Слот 4", "Слот 5"};
  bool gameStart_ = true;
  bool gameOver_ = false;
  bool coinStop_ = true;

  int menuPoint = 0;

 public:
  void initializeNew();
  void initializeLoad();
  void update();
  void renderHUD();
  void endGame();
  void setSprites();
  void setMenu();

  void gameMenu();
  void loadMenu();

  bool isCoinStop() const;
  void setCoinStop(bool coinStop);
  bool isGameStart() const;
  void setGameStart(bool gameStart);
  int getMenuPoint() const;
  void setMenuPoint(int menuPoint);
  explicit GameInit(Controls* controls);
};

#endif  // INCLUDE_GAME_GAMEINIT_H_
