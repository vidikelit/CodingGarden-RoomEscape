#include "game/gameMenu.h"
#include <vector>

void GameMenu::update() {
  terminal_clear();
  if (menu_ == 2) settingMenu();
  if (menu_ == 1) loadMenu();
  if (menu_ == 0) mainMenu();
}
void GameMenu::mainMenu() {
  terminal_print(5, 5, "[color=red]Room \n    Escape");
  for (unsigned int i = 0; i < pointMainMenu.size(); i++) {
    if (getMenuPoint() == static_cast<int>(i)) {
      terminal_color(color_from_name("green"));
    }
    terminal_printf(5, 8 + i, "%s", pointMainMenu[i]);
    terminal_color(color_from_name("white"));
    if (controls->isEnter()) {
      // продолжить игру
      if (strcmp(pointMainMenu[getMenuPoint()], continue_game_) == 0) {
        setGameMenuStatus(false);
        setContinueGame(true);
        break;
      }
      // новая игра
      if (strcmp(pointMainMenu[getMenuPoint()], new_game_) == 0) {
        setGameMenuStatus(false);
        setMenuPoint(0);
        setNewGame(true);
        break;
      }
      // загрузить игру
      if (strcmp(pointMainMenu[getMenuPoint()], load_game_) == 0) {
        setMenuPoint(0);
        setMenu(1);
        break;
      }
      // настройки
      if (strcmp(pointMainMenu[getMenuPoint()], setting_game_) == 0) {
        setMenuPoint(0);
        setMenu(2);
        break;
      }
      // выход
      if (strcmp(pointMainMenu[getMenuPoint()], end_game_) == 0) {
        setEndGame(true);
        break;
      }
    }
  }
  if (controls->isUp()) {
    setMenuPoint(getMenuPoint() - 1);
    if (getMenuPoint() < 0) setMenuPoint(pointMainMenu.size() - 1);
  }
  if (controls->isDown()) {
    setMenuPoint(getMenuPoint() + 1);
    if (getMenuPoint() > static_cast<int>(pointMainMenu.size()) - 1) setMenuPoint(0);
  }
  terminal_color(color_from_name("white"));
}
void GameMenu::loadMenu() {
  terminal_clear();
  terminal_print(5, 5, "[color=red]Загрузить\n генерацию");
  for (unsigned int i = 0; i < pointLoadMenu.size(); i++) {
    if (getMenuPoint() == static_cast<int>(i)) {
      terminal_color(color_from_name("green"));
    }
    terminal_printf(7, 8 + i, "%s", pointLoadMenu[i]);
    terminal_color(color_from_name("white"));
    if (controls->isEnter()) {
      // Слот 1
      if (strcmp(pointLoadMenu[getMenuPoint()], slot1_) == 0) {
        setSlot(0);
        setLoadGame(true);
        break;
      }
    }
  }
  if (controls->isUp()) {
    setMenuPoint(getMenuPoint() - 1);
    if (getMenuPoint() < 0) setMenuPoint(pointLoadMenu.size() - 1);
  }
  if (controls->isDown()) {
    setMenuPoint(getMenuPoint() + 1);
    if (getMenuPoint() > static_cast<int>(pointLoadMenu.size()) - 1) setMenuPoint(0);
  }
  if (controls->isEsc()) {
    setMenu(0);
    setMenuPoint(0);
  }
  terminal_color(color_from_name("white"));
}
void GameMenu::settingMenu() {
  terminal_clear();
  terminal_print(5, 5, "[color=red]Настройка\n графики");
  for (unsigned int i = 0; i < pointSettingMenu.size(); i++) {
    if (getMenuPoint() == static_cast<int>(i)) terminal_color(color_from_name("green"));
    terminal_printf(7, 8 + i, "%s", pointSettingMenu[i]);
    terminal_color(color_from_name("white"));
    if (controls->isEnter()) {
      // Настройка графики
      if (strcmp(pointSettingMenu[getMenuPoint()], tiles_) == 0) {
        setSettingGame(true);
        if (isSettingGameOnOff()) {
          pointSettingMenu.at(i) = "Тайлы [color=red]OFF";
          setTiles("Тайлы [color=red]OFF");
          setSettingGameOnOff(false);
        } else {
          pointSettingMenu.at(i) = "Тайлы [color=green]ON";
          setTiles("Тайлы [color=green]ON");
          setSettingGameOnOff(true);
        }
      }
    }
  }
  //  if (controls->isUp()) {
  //    setMenuPoint(getMenuPoint() - 1);
  //    if (getMenuPoint() < 0) setMenuPoint(pointSettingMenu.size() - 1);
  //  }
  //  if (controls->isDown()) {
  //    setMenuPoint(getMenuPoint() + 1);
  //    if (getMenuPoint() > static_cast<int>(pointSettingMenu.size()) - 1) setMenuPoint(0);
  //  }
  if (controls->isEsc()) {
    setMenu(0);
    setMenuPoint(0);
  }
  terminal_color(color_from_name("white"));
}
void GameMenu::setNewMenuPoint() {
  pointMainMenu.insert(pointMainMenu.begin(), continue_game_);
}
int GameMenu::getMenuPoint() const {
  return menuPoint_;
}
void GameMenu::setMenuPoint(int menuPoint) {
  GameMenu::menuPoint_ = menuPoint;
}
int GameMenu::getMenu() const {
  return menu_;
}
void GameMenu::setMenu(int menu) {
  GameMenu::menu_ = menu;
}
void GameMenu::setControls(Controls* controls) {
  GameMenu::controls = controls;
}
bool GameMenu::isGameMenuStatus() const {
  return gameMenuStatus_;
}
void GameMenu::setGameMenuStatus(bool gameMenuStatus) {
  GameMenu::gameMenuStatus_ = gameMenuStatus;
}
bool GameMenu::isNewGame() const {
  return newGame_;
}
void GameMenu::setNewGame(bool newGame) {
  GameMenu::newGame_ = newGame;
}
const std::vector<const char*>& GameMenu::getPointMainMenu() const {
  return pointMainMenu;
}
const char* GameMenu::getContinueGame() const {
  return continue_game_;
}
bool GameMenu::isEndGame() const {
  return endGame_;
}
void GameMenu::setEndGame(bool endGame) {
  endGame_ = endGame;
}
bool GameMenu::isContinueGame() const {
  return continueGame_;
}
void GameMenu::setContinueGame(bool continueGame) {
  continueGame_ = continueGame;
}
bool GameMenu::isLoadGame() const {
  return loadGame_;
}
void GameMenu::setLoadGame(bool loadGame) {
  loadGame_ = loadGame;
}
int GameMenu::getSlot() const {
  return slot_;
}
void GameMenu::setSlot(int slot) {
  GameMenu::slot_ = slot;
}
bool GameMenu::isSettingGame() const {
  return settingGame_;
}
void GameMenu::setSettingGame(bool settingGame) {
  settingGame_ = settingGame;
}
bool GameMenu::isSettingGameOnOff() const {
  return settingGameOnOff_;
}
void GameMenu::setSettingGameOnOff(bool settingGameOnOff) {
  settingGameOnOff_ = settingGameOnOff;
}
void GameMenu::setTiles(const char* tiles) {
  tiles_ = tiles;
}
