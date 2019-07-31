#include "game/gameLogic.h"
#include <tgmath.h>
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
  miniMap = MiniMap(&gameMap);
  gameMap.generatorMap();
  miniMap.generatorMiniMap();
  gameMap.render(0);
  miniMap.render();
  player.setX(10);
  player.setY(11);
  setRun(true);
  setExitLevel(false);
}
// загрузка игры
void GameLogic::loadGame() {
  terminal_layer(0);
  terminal_clear_area(0, 0, 21, 17);
  if (strcmp(gameMenu.getPointMainMenu()[0], gameMenu.getContinueGame()) != 0) gameMenu.setNewMenuPoint();
  gameMenu.setMenuPoint(0);
  gameMap = GameMap();
  miniMap = MiniMap(&gameMap);
  saverLoader.setMap(&gameMap);
  saverLoader.loader();
  gameMap.setDoorCoin();
  miniMap.generatorMiniMap();
  gameMap.render(0);
  miniMap.render();
  setRun(true);
  setExitLevel(false);
}
// конец игры - вывод статистики
void GameLogic::endGame() {
  terminal_clear();
  terminal_print(5, 5, "[color=green]Статистика:");
  terminal_printf(6, 7, "Шагов=%d", player.getSteps());
  terminal_printf(6, 8, "Монет=%d", player.getCoin());
  terminal_printf(4, gameMap.getCurrentRoom().getRoomSizeY() - 2, "Нажмите [color=red]Enter[color=white],");
  terminal_printf(2, gameMap.getCurrentRoom().getRoomSizeY() - 1, "чтобы выйти в меню");
}
// обновление меню
void GameLogic::updateMenu() {
  if (gameMenu.isGameMenuStatus()) {
    gameMenu.update();
  }
  if (renderSave_) {
    renderSave();
  }
  // продолжить
  if (gameMenu.isContinueGame()) {
    gameMenu.setContinueGame(false);
    setRun(true);
    gameMap.render(gameMap.getNumberRoom());
    miniMap.render();
  }
  // новая игра
  if (gameMenu.isNewGame()) {
    gameMenu.setNewGame(false);
    newGame();
    setEnd(false);
  }
  // сохранить игру
  if (gameMenu.isSaveGame()) {
    gameMenu.setSaveGame(false);
    gameMenu.setGameMenuStatus(false);
    renderSave_ = true;
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
void GameLogic::renderSave() {
  terminal_clear();
  terminal_print(0, 8, "Генерация сохранена");
  terminal_print(3, 10, "Нажмите [color=red]Enter");
  if (controls->isEnter()) {
    renderSave_ = false;
    gameMenu.setGameMenuStatus(true);
  }
}
// обновление игры
void GameLogic::update() {
  // очистка поля
  terminal_layer(2);
  terminal_clear_area(0, 0, 21, 17);

  if (isEndGame()) {
    endGame();
    if (controls->isEnter()) {
      setRun(false);
      gameMenu.setGameMenuStatus(true);
      gameMenu.setMenu(0);
      setEndGame(false);
    }
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
    terminal_print(7, 9, "Press E");
  }
  setPlayerX(player.getX());
  setPlayerY(player.getY());
  // выход на E
  if (controls->isE()) {
    scanner(player.getX(), player.getY(), gameMap.getNumberRoom());
    player.setX(getPlayerX());
    player.setY(getPlayerY());
    if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getSymbolExit()) {
      endGame_ = true;
    }
  }
  playerMove();
  player.update();
  // сбор монет
  if (gameMap.getCurrentRoom().getCoinCount() != 0) {
    if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getCoin(0).getSymbolCoin()) {
      for (int i = 0; i < gameMap.getCurrentRoom().getCoinCount(); i++) {
        if (player.getX() == gameMap.getCurrentRoom().getCoin(i).getX() &&
            player.getY() == gameMap.getCurrentRoom().getCoin(i).getY()) {
          gameMap.getCurrentRoom().removeCoin(i);
          player.setCoin(player.getCoin() + 1);
        }
      }
    }
  }
  // выход в меню
  if (controls->isEsc()) {
    setRun(false);
    gameMenu.setGameMenuStatus(true);
    gameMenu.setMenu(0);
  }
  stats();
}
void GameLogic::interWall(int x, int y) {
  terminal_layer(0);
  // верхняя стена
  if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getWall()) {
    player.setSteps(player.getSteps() - 1);
    player.setX(x);
    player.setY(y);
  }
}
// установка спрайтов
void GameLogic::setSprites() {
  terminal_set("0x40: ./resources/sprites/player.png");
  terminal_set("0x25: ./resources/sprites/signExit.png");
  terminal_set("0x24: ./resources/sprites/coinGold.png");
}
void GameLogic::playerMove() {
  int x = player.getX();
  int y = player.getY();
  if (controls->isUp()) {
    player.setY(player.getY() - player.getSpeed());
    player.setSteps(player.getSteps() + 1);
  }
  if (controls->isDown()) {
    player.setY(player.getY() + player.getSpeed());
    player.setSteps(player.getSteps() + 1);
  }
  if (controls->isLeft()) {
    player.setX(player.getX() - player.getSpeed());
    player.setSteps(player.getSteps() + 1);
  }
  if (controls->isRight()) {
    player.setX(player.getX() + player.getSpeed());
    player.setSteps(player.getSteps() + 1);
  }
  interWall(x, y);
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
void GameLogic::scanner(int x, int y, int n) {
  for (int i = 0; i <= 3; i++) {
    if (sqrt(pow(gameMap.getRooms().at(n).doorsCoords[i][0] - x, 2) +
             pow(gameMap.getRooms().at(n).doorsCoords[i][1] - y, 2)) <= 1) {
      if (gameMap.getRooms().at(n).doors[i]) {
        teleport(i);
        miniMap.mapMove(i);
        miniMap.render();
        playerPos(x, y, i);
        break;
      }
    }
  }
}
void GameLogic::playerPos(int x, int y, int n) {
  setPlayerX(x);
  setPlayerY(y);
  if (n == 0) setPlayerY(getPlayerY() + 8);
  if (n == 1) setPlayerY(getPlayerY() - 8);
  if (n == 2) setPlayerX(getPlayerX() + 18);
  if (n == 3) setPlayerX(getPlayerX() - 18);
}
void GameLogic::teleport(int i) {
  int buff_x = 0;
  int buff_y = 0;
  if (i == 0) buff_y -= gameMap.getRooms().at(0).getRoomSizeY();
  if (i == 1) buff_y += gameMap.getRooms().at(0).getRoomSizeY();
  if (i == 2) buff_x -= gameMap.getRooms().at(0).getRoomSizeX();
  if (i == 3) buff_x += gameMap.getRooms().at(0).getRoomSizeX();

  for (unsigned int n = 0; n < gameMap.getRooms().size(); n++) {
    if (gameMap.getRooms().at(gameMap.getNumberRoom()).getX() + buff_x == gameMap.getRooms().at(n).getX()) {
      if (gameMap.getRooms().at(gameMap.getNumberRoom()).getY() + buff_y == gameMap.getRooms().at(n).getY()) {
        gameMap.setNumberRoom(n);
        gameMap.render(n);
        break;
      }
    }
  }
}
int GameLogic::getPlayerX() const {
  return player_x_;
}
void GameLogic::setPlayerX(int playerX) {
  player_x_ = playerX;
}
int GameLogic::getPlayerY() const {
  return player_y_;
}
void GameLogic::setPlayerY(int playerY) {
  player_y_ = playerY;
}
bool GameLogic::isEndGame() const {
  return endGame_;
}
void GameLogic::setEndGame(bool endGame) {
  endGame_ = endGame;
}
void GameLogic::stats() {
  terminal_layer(4);
  terminal_clear_area(5, 0, 21, 5);
  terminal_put(6, 0, 0x40);
  terminal_printf(7, 0, "=%d", player.getSteps());

  terminal_put(6, 1, 0x24);
  terminal_printf(7, 1, "=%d", player.getCoin());
  terminal_layer(2);
}
