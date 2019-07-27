#include "game/gameMenu.h"
#include <vector>

void GameMenu::update() {
  terminal_clear();
  if (menu_ == 1 || menu_ == 2) saveLoadMenu();
  if (menu_ == 0) mainMenu();
}
void GameMenu::mainMenu() {
  terminal_print(9, 5, "[color=red]Room Escape");
  for (unsigned int i = 0; i < pointMainMenu.size(); i++) {
    if (getMenuPoint() == static_cast<int>(i)) {
      terminal_color(color_from_name("green"));
    }
    terminal_printf(9, 8 + i, "%s", pointMainMenu[i]);
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
        setNewGame(true);
        break;
      }
      // сохранить игру
      if (strcmp(pointMainMenu[getMenuPoint()], save_game_) == 0) {
        setMenuPoint(0);
        setMenu(1);
        break;
      }
      // загрузить игру
      if (strcmp(pointMainMenu[getMenuPoint()], load_game_) == 0) {
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
void GameMenu::saveLoadMenu() {
  terminal_clear();
  if (getMenu() == 1)
    terminal_print(9, 5, "[color=red]Сохранить\nгенерацию");
  else
    terminal_print(9, 5, "[color=red]Загрузить\nгенерацию");
  for (unsigned int i = 0; i < pointSaveLoadMenu.size(); i++) {
    if (getMenuPoint() == static_cast<int>(i)) {
      terminal_color(color_from_name("green"));
    }
    terminal_printf(9, 8 + i, "%s", pointSaveLoadMenu[i]);
    terminal_color(color_from_name("white"));
    if (controls->isEnter()) {
      // Слот 1
      if (strcmp(pointSaveLoadMenu[getMenuPoint()], slot1_) == 0) {
        setSlot(0);
        if (getMenu() == 1)
          setSaveGame(true);
        else
          setLoadGame(true);
        break;
      }
      // Слот 2
      if (strcmp(pointSaveLoadMenu[getMenuPoint()], slot2_) == 0) {
        setSlot(1);
        if (getMenu() == 1)
          setSaveGame(true);
        else
          setLoadGame(true);
        break;
      }
      // Слот 3
      if (strcmp(pointSaveLoadMenu[getMenuPoint()], slot3_) == 0) {
        setSlot(2);
        if (getMenu() == 1)
          setSaveGame(true);
        else
          setLoadGame(true);
        break;
      }
    }
  }
  if (controls->isUp()) {
    setMenuPoint(getMenuPoint() - 1);
    if (getMenuPoint() < 0) setMenuPoint(pointSaveLoadMenu.size() - 1);
  }
  if (controls->isDown()) {
    setMenuPoint(getMenuPoint() + 1);
    if (getMenuPoint() > static_cast<int>(pointSaveLoadMenu.size()) - 1) setMenuPoint(0);
  }
  if (controls->isEsc()) {
    setMenu(0);
    setMenuPoint(0);
  }
  terminal_color(color_from_name("white"));
}

void GameMenu::setNewMenuPoint() {
  pointMainMenu.insert(pointMainMenu.begin(), continue_game_);
  pointMainMenu.insert(pointMainMenu.begin() + 2, save_game_);
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
bool GameMenu::isSaveGame() const {
  return saveGame_;
}
void GameMenu::setSaveGame(bool saveGame) {
  saveGame_ = saveGame;
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
