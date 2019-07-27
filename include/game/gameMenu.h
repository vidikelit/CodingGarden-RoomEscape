#ifndef INCLUDE_GAME_GAMEMENU_H_
#define INCLUDE_GAME_GAMEMENU_H_

#include <BearLibTerminal.h>
#include <cstring>
#include <vector>
#include "game/controls.h"
#include "game/map.h"

class GameMenu {
 private:
  Controls* controls;
  // пункты основного меню
  const char* continue_game_ = "Продолжить";
  const char* new_game_ = "Новая игра";
  const char* save_game_ = "Сохранить";
  const char* load_game_ = "Загрузить";
  const char* end_game_ = "Выход";

  // пункты меню сохранения/загрузки
  const char* slot1_ = "Слот 1";
  const char* slot2_ = "Слот 2";
  const char* slot3_ = "Слот 3";

  std::vector<const char*> pointMainMenu{new_game_, load_game_, end_game_};
  std::vector<const char*> pointSaveLoadMenu{slot1_, slot2_, slot3_};

  // 0 - основное меню, 1 - меню сохранений, 2 - меню загрузки
  int menu_ = 0;
  int menuPoint_ = 0;
  // слот сохранений
  int slot_;

 private:
  // основное меню
  bool gameMenuStatus_ = true;
  bool newGame_ = false;
  bool saveGame_ = false;
  bool loadGame_ = false;
  bool continueGame_ = false;
  bool endGame_ = false;

 public:
  void update();
  void mainMenu();
  void saveLoadMenu();
  void setNewMenuPoint();

  int getMenu() const;
  void setMenu(int menu);
  bool isGameMenuStatus() const;
  void setGameMenuStatus(bool gameMenuStatus);
  bool isNewGame() const;
  void setNewGame(bool newGame);
  int getMenuPoint() const;
  void setMenuPoint(int menuPoint);
  void setControls(Controls* controls);
  const std::vector<const char*>& getPointMainMenu() const;
  const char* getContinueGame() const;
  bool isEndGame() const;
  void setEndGame(bool endGame);
  bool isContinueGame() const;
  void setContinueGame(bool continueGame);
  bool isSaveGame() const;
  void setSaveGame(bool saveGame);
  bool isLoadGame() const;
  void setLoadGame(bool loadGame);
  int getSlot() const;
  void setSlot(int slot);
};

#endif  // INCLUDE_GAME_GAMEMENU_H_
