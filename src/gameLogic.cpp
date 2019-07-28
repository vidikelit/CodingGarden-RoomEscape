#include "game/gameLogic.h"
#include "game/gameMenu.h"

// инициализация объектов игры
void GameLogic::initGame() {
  setSprites();
}
// новая игра
void GameLogic::newGame() {
  if (strcmp(gameMenu.getPointMainMenu()[0], gameMenu.getContinueGame()) != 0) gameMenu.setNewMenuPoint();
  terminal_clear();
  gameMap = GameMap();
  gameMap.generatorMap();
  gameMap.render(0);
  setRun(true);
  setExitLevel(false);
}
// загрузка сохраненной игры
void GameLogic::loadGame() {
  if (strcmp(gameMenu.getPointMainMenu()[0], gameMenu.getContinueGame()) != 0) gameMenu.setNewMenuPoint();
  gameMenu.setMenuPoint(0);
  gameMap = GameMap();
  saverLoader.setMap(&gameMap);
  saverLoader.loader();
  player.setCoin(0);
  player.setSteps(0);
  gameMap.setDoorCoin();
  gameMap.render(0);
  setRun(true);
  setExitLevel(false);
}
// конец игры - вывод статистики
void GameLogic::endGame() {
  terminal_clear();
  terminal_print(0, 0, "Статистика:");
  terminal_printf(1, 2, "Шагов=%d", player.getSteps());
  terminal_printf(1, 3, "Монет=%d", player.getCoin());
}
// обновление меню
void GameLogic::updateMenu() {
  if (gameMenu.isGameMenuStatus()) {
    gameMenu.update();
  }
  // продолжить
  if (gameMenu.isContinueGame()) {
    gameMenu.setContinueGame(false);
    setRun(true);
    gameMap.render(gameMap.getNumberRoom());
  }
  // новая игра
  if (gameMenu.isNewGame()) {
    gameMenu.setNewGame(false);
    newGame();
  }
  // сохранить игру
  if (gameMenu.isSaveGame()) {
    gameMenu.setSaveGame(false);
    saverLoader.setSaveSlot(gameMenu.getSlot());
    saverLoader.setMap(&gameMap);
    saverLoader.saver();
  }
  // загрузить игру
  if (gameMenu.isLoadGame()) {
    gameMenu.setLoadGame(false);
    saverLoader.setSaveSlot(gameMenu.getSlot());
    loadGame();
  }
  // выход
  if (gameMenu.isEndGame()) {
    setEnd(true);
    setRun(false);
  }
}
// обновление игры
void GameLogic::update() {
  terminal_layer(1);
  terminal_clear_area(0, 0, 31, 21);
  terminal_layer(0);
  terminal_clear_area(1, 6, 29, 14);
  if (endGame_) {
    endGame();
    return;
  }
  // если в комнатах нет монет, то ставится выход
  if (gameMap.getAllCoin() == 0 && !isExitLevel()) {
    gameMap.getCurrentRoom().setExit(true);
    setExitLevel(true);
  }
  gameMap.renderCoin(gameMap.getNumberRoom());
  // сообщение о нажатии клавиши
  if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getSymbolExit()) {
    terminal_print(12, 11, "Press E");
  }
  gameMap.player_x_ = player.getX();
  gameMap.player_y_ = player.getY();
  // выход на E
  if (controls->isE()) {
    gameMap.scanner(player.getX(), player.getY(), gameMap.getNumberRoom());
    player.setX(gameMap.player_x_);
    player.setY(gameMap.player_y_);
    if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getSymbolExit()) {
      endGame_ = true;
    }
  }
  player.update();
  // сбор монет
  if (gameMap.getCurrentRoom().getCoinCount() != 0) {
    terminal_layer(1);
    if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getCoin(0).getSymbolCoin()) {
      for (int i = 0; i < gameMap.getCurrentRoom().getCoinCount(); i++) {
        if (player.getX() == gameMap.getCurrentRoom().getCoin(i).getX() &&
            player.getY() == gameMap.getCurrentRoom().getCoin(i).getY()) {
          gameMap.getCurrentRoom().removeCoin(i);
          player.setCoin(player.getCoin() + 1);
        }
      }
    }
    terminal_layer(0);
  }
  // выход в меню
  if (controls->isEsc()) {
    setRun(false);
    gameMenu.setGameMenuStatus(true);
    gameMenu.setMenu(0);
  }
}
// установка спрайтов
void GameLogic::setSprites() {
  terminal_set("0x40: ./resources/sprites/player.png");
  terminal_set("0x23: ./resources/sprites/castle.png");
  terminal_set("0x3E: ./resources/sprites/door.png");
  terminal_set("0x25: ./resources/sprites/signExit.png");
  terminal_set("0x24: ./resources/sprites/coinGold.png");
}
GameLogic::GameLogic(Controls *controls) : controls(controls) {
  gameMenu.setControls(controls);
}
bool GameLogic::isRun() const {
  return run_;
}
void GameLogic::setRun(bool run) {
  run_ = run;
}
bool GameLogic::isEnd() const {
  return end_;
}
void GameLogic::setEnd(bool end) {
  end_ = end;
}
bool GameLogic::isExitLevel() const {
  return exitLevel_;
}
void GameLogic::setExitLevel(bool exitLevel) {
  exitLevel_ = exitLevel;
}
