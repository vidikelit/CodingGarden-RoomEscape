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
  map = Map();
  map.generator();
  map.render(0);
  setRun(true);
}
// загрузка сохраненной игры
void GameLogic::loadGame() {
  if (strcmp(gameMenu.getPointMainMenu()[0], gameMenu.getContinueGame()) != 0) gameMenu.setNewMenuPoint();
  gameMenu.setMenuPoint(0);
  map = Map();
  saverLoader.setMap(&map);
  saverLoader.loader();
  player.setCoin(0);
  player.setSteps(0);
  map.setDoorCoin();
  map.render(0);
  setRun(true);
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
    map.render(map.getNumberRoom());
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
    saverLoader.setMap(&map);
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
  terminal_clear_area(1, 1, 19, 19);
  terminal_layer(0);
  terminal_clear_area(1, 1, 19, 19);
  if (endGame_) {
    endGame();
    return;
  }
  // если в комнатах нет монет, то ставится выход
  if (map.getAllCoin() == 0) {
    map.getCurrentRoom().setExit(true);
  }
  map.renderCoin(map.getNumberRoom());
  // сообщение о нажатии клавиши
  if (terminal_pick(player.getX(), player.getY(), 0) == map.getCurrentRoom().getSymbolExit()) {
    terminal_print(7, 8, "Press E");
  }
  map.player_x_ = player.getX();
  map.player_y_ = player.getY();
  // выход на E
  if (controls->isE()) {
    map.scanner(player.getX(), player.getY(), map.number_room_);
    player.setX(map.player_x_);
    player.setY(map.player_y_);
    if (terminal_pick(player.getX(), player.getY(), 0) == map.getCurrentRoom().getSymbolExit()) {
      endGame_ = true;
    }
  }
  player.update();
  // сбор монет
  if (map.getCurrentRoom().getCoinCount() != 0) {
    terminal_layer(1);
    if (terminal_pick(player.getX(), player.getY(), 0) == map.getCurrentRoom().getCoin(0).getSymbolCoin()) {
      for (int i = 0; i < map.getCurrentRoom().getCoinCount(); i++) {
        if (player.getX() == map.getCurrentRoom().getCoin(i).getX() &&
            player.getY() == map.getCurrentRoom().getCoin(i).getY()) {
          map.getCurrentRoom().removeCoin(i);
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
