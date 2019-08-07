#ifndef INCLUDE_GAME_GAMEMENU_H_
#define INCLUDE_GAME_GAMEMENU_H_

#include <BearLibTerminal.h>
#include <cstring>
#include <vector>
#include "game/controls.h"
#include "game/gameMap.h"

class GameMenu {
 private:
  Controls* controls;
  // пункты основного меню
  const char* continue_game_ = "Продолжить";
  const char* new_game_ = "Новая игра";
  const char* load_game_ = "Загрузить";
  const char* setting_game_ = "Настройки";
  const char* end_game_ = "Выход";

  // пункты меню сохранения/загрузки
  const char* slot1_ = "Слот 1";
  const char* slot2_ = "Слот 2";
  const char* slot3_ = "Слот 3";

  // меню настроек
  const char* tiles_ = "Тайлы [color=green]ON";

  std::vector<const char*> pointMainMenu{new_game_, load_game_, setting_game_, end_game_};
  std::vector<const char*> pointLoadMenu{slot1_};
  std::vector<const char*> pointSettingMenu{tiles_};

  // 0 - основное меню, 1 - меню сохранений, 2 - меню загрузки
  int menu_ = 0;
  int menuPoint_ = 0;
  // слот сохранений
  int slot_;

  // основное меню
  bool gameMenuStatus_ = true;
  bool newGame_ = false;
  bool loadGame_ = false;
  bool settingGame_ = false;
  bool settingGameOnOff_ = true;
  bool continueGame_ = false;
  bool endGame_ = false;

 public:
  void update();
  void mainMenu();
  void loadMenu();
  void settingMenu();
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
  bool isLoadGame() const;
  void setLoadGame(bool loadGame);
  bool isSettingGame() const;
  void setSettingGame(bool settingGame);
  bool isSettingGameOnOff() const;
  void setSettingGameOnOff(bool settingGameOnOff);
  int getSlot() const;
  void setSlot(int slot);
  void setTiles(const char* tiles);
};

#endif  // INCLUDE_GAME_GAMEMENU_H_
