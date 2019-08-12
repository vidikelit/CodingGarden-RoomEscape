#include "game/gameLogic.h"
#include <tgmath.h>

// инициализация объектов игры
void GameLogic::initGame() {
  terminal_clear();
  setSprites();
  setRun(true);
  setExitLevel(false);
}
// установка спрайтов
void GameLogic::setSprites() {
  if (gameMenu.isSettingGameOnOff()) {
    terminal_set("0x40: ./resources/sprites/player.png");
    terminal_set("0x25: ./resources/sprites/elevator.png");
    terminal_set("0x24: ./resources/sprites/coinGold.png");
    gameMap.setTilesRooms(true);
    miniMap.setTiles(true);
  } else {
    terminal_set("0x40: none");
    terminal_set("0x25: none");
    terminal_set("0x24: none");
    gameMap.setTilesRooms(false);
    miniMap.setTiles(false);
  }
}
// новая игра
void GameLogic::newGame() {
  initGame();
  setLevel(0);
  saverLoader.newFile();
  // создание карты
  gameMap = GameMap();
  gameMap.update();
  gameMap.getCurrentRoom().renderRoom();
  // создание и отрисовка миникарты
  miniMap = MiniMap(&gameMap);
  miniMap.update();
  // начальные настройки персонажа
  player.setDefault();
}
// загрузка игры
void GameLogic::loadGame() {
  initGame();
  // создание карты
  gameMap = GameMap();
  saverLoader.setLevel(getLevel());  // потом заменим на пользовательские настройки
  saverLoader.setMap(&gameMap);
  saverLoader.loader();
  gameMap.updateDoor();
  gameMap.getCurrentRoom().renderRoom();
  // создание и отрисовка миникарты
  miniMap = MiniMap(&gameMap);
  miniMap.update();
}
// новый уровень
void GameLogic::newLevel() {
  terminal_clear();
  // сохранение текущего уровня
  saveLevel();
  // установка значения нового уровня
  setLevel(getLevel() + 1);
  // создание карты
  gameMap = GameMap();
  gameMap.update();
  gameMap.getCurrentRoom().renderRoom();
  // создание миникарты
  miniMap = MiniMap(&gameMap);
  miniMap.update();
}
// возвращение на предыдущий
void GameLogic::prevLevel() {
  setLevel(getLevel() - 1);
  initGame();
  // создание карты
  gameMap = GameMap();
  saverLoader.setLevel(getLevel());
  saverLoader.setMap(&gameMap);
  saverLoader.loader();
  gameMap.setNumberRoom(gameMap.getRooms().size() - 1);
  gameMap.updateDoor();
  gameMap.getCurrentRoom().renderRoom();
  // создание и отрисовка миникарты
  miniMap = MiniMap(&gameMap);
  miniMap.generatorMiniMap();
  miniMap.miniMapBack();
  miniMap.render();
}
// сохранение текущего уровня
void GameLogic::saveLevel() {
  saverLoader.setLevel(getLevel());
  saverLoader.setMap(&gameMap);
  saverLoader.saver();
}
// вывод сообщения о сохранении
void GameLogic::renderSave() {
  terminal_clear();
  terminal_printf(2, 7, "Уровень [color=green]%d [color=white]пройден", getLevel());
  terminal_print(1, 9, "Генерация сохранена");
  terminal_print(4, 15, "Нажмите [color=red]Enter");
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
    gameMap.getCurrentRoom().renderRoom();
    miniMap.render();
  }
  // новая игра
  if (gameMenu.isNewGame()) {
    if (strcmp(gameMenu.getPointMainMenu()[0], gameMenu.getContinueGame()) != 0) gameMenu.setNewMenuPoint();
    gameMenu.setNewGame(false);
    newGame();
    setEnd(false);
  }
  // загрузить игру
  if (gameMenu.isLoadGame()) {
    gameMenu.setLoadGame(false);
    if (strcmp(gameMenu.getPointMainMenu()[0], gameMenu.getContinueGame()) != 0) gameMenu.setNewMenuPoint();
    setLevel(0);  // потом установим по пользовательским настройкам
    loadGame();
  }
  // настройки
  if (gameMenu.isSettingGame()) {
    gameMenu.setSettingGame(false);
    initGame();
  }
  // выход
  if (gameMenu.isEndGame()) {
    saveLevel();
    setEnd(true);
    setRun(false);
  }
}
// обновление игры
void GameLogic::update() {
  // очистка поля
  terminal_layer(10);
  terminal_clear_area(0, 0, 21, 17);
  terminal_layer(1);
  terminal_clear_area(0, 0, 21, 17);
  terminal_layer(2);
  terminal_clear_area(0, 0, 21, 17);
  // отрисовка монет
  gameMap.getCurrentRoom().renderCoin();
  // автосохранение
  if (renderSave_) {
    renderSave();
    if (controls->isEnter()) {
      renderSave_ = false;
      gameMap.getCurrentRoom().renderRoom();
      miniMap.render();
    }
    return;
  }
  // обработка конца игры
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
  // установка выхода в последней комнате, если монет на карте нет
  if (gameMap.getAllCoin() == 0) gameMap.getRooms().back().setElevator();
  // установка выхода в первой комнате
  if (getLevel() != 0) gameMap.getRooms().at(0).setElevator();
  terminal_layer(0);
  if (gameMap.getCurrentRoom().getElevator().isExit()) gameMap.getCurrentRoom().renderElevator();
  setPlayerX(player.getX());
  setPlayerY(player.getY());
  if (terminal_pick(player.getX(), player.getY(), 1) == gameMap.getCurrentRoom().getElevator().getSymbolEvelator()) {
    terminal_layer(10);
    if (gameMap.getNumberRoom() == 0)
      terminal_printf(7, 10, "Back L%d", getLevel());
    else
      terminal_printf(8, 10, "Go L%d", getLevel() + 2);
  }
  // заходим в дверь
  if (controls->isE()) {
    scanner();
    terminal_layer(0);
    if (terminal_pick(player.getX(), player.getY(), 1) == gameMap.getCurrentRoom().getElevator().getSymbolEvelator() &&
        getLevel() == 4) {
      if (gameMap.getNumberRoom() == 0) {
        saveLevel();
        prevLevel();
      } else {
//        renderSave_ = true;
        endGame_ = true;
      }
    }
    if (terminal_pick(player.getX(), player.getY(), 1) == gameMap.getCurrentRoom().getElevator().getSymbolEvelator() &&
        getLevel() != 4) {
      if (gameMap.getNumberRoom() == 0) {
        saveLevel();
        prevLevel();
      } else {
//        renderSave_ = true;
        saverLoader.lineCheck(getLevel() + 1);
        if (!saverLoader.isClearLine()) {
          setLevel(getLevel() + 1);
          loadGame();
        } else {
          newLevel();
        }
      }
    }
  }
  // сбор монет
  terminal_layer(1);
  if (gameMap.getCurrentRoom().getCoinCount() != 0) {
    if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getCoinSymbol()) {
      for (int i = 0; i < gameMap.getCurrentRoom().getCoinCount(); i++) {
        if (player.getX() == gameMap.getCurrentRoom().getCoins().at(i).getX() &&
            player.getY() == gameMap.getCurrentRoom().getCoins().at(i).getY()) {
          gameMap.getCurrentRoom().removeCoin(i);
          player.addCoin();
        }
      }
    }
  }
  playerMove();
  player.update();
  stats();
  // выход в меню
  if (controls->isEsc()) {
    setRun(false);
    gameMenu.setGameMenuStatus(true);
    gameMenu.setMenu(0);
  }
}
// вывод статистики
void GameLogic::stats() {
  terminal_layer(10);
  terminal_clear_area(5, 0, 21, 5);
  terminal_put(6, 1, 0x40);
  terminal_printf(7, 1, "=%d", player.getSteps());

  terminal_put(6, 2, 0x24);
  terminal_printf(7, 2, "=%d", player.getCoin());

  terminal_printf(16, 5, "L=%d/5", getLevel() + 1);
  terminal_layer(2);
}
void GameLogic::scanner() {
  for (unsigned int i = 0; i < gameMap.getCurrentRoom().getDoors().size(); i++) {
    if (sqrt(pow(gameMap.getRooms().at(gameMap.getNumberRoom()).getDoors().at(i).getX() - player.getX(), 2) +
             pow(gameMap.getRooms().at(gameMap.getNumberRoom()).getDoors().at(i).getY() - player.getY(), 2)) <= 1) {
      teleport();
      gameMap.getCurrentRoom().renderRoom();
      miniMap.render();
      break;
    }
  }
}
void GameLogic::teleport() {
  int move_x = 0;
  int move_y = 0;
  setPlayerX(player.getX());
  setPlayerY(player.getY());
  // перемещение игрока
  // вверх
  if (player.getX() == 10 && player.getY() == 7) {
    setPlayerY(player.getY() + 8);
    move_y -= gameMap.getRooms().at(0).getRoomSizeY();
    miniMap.mapMove(0);
  }
  // вниз
  if (player.getX() == 10 && player.getY() == 15) {
    setPlayerY(player.getY() - 8);
    player.setY(player.getY() - 8);
    move_y += gameMap.getRooms().at(0).getRoomSizeY();
    miniMap.mapMove(1);
  }
  // влево
  if (player.getX() == 1 && player.getY() == 11) {
    setPlayerX(player.getX() + 18);
    move_x -= gameMap.getRooms().at(0).getRoomSizeX();
    miniMap.mapMove(2);
  }
  // вправо
  if (player.getX() == 19 && player.getY() == 11) {
    setPlayerX(player.getX() - 18);
    move_x += gameMap.getRooms().at(0).getRoomSizeX();
    miniMap.mapMove(3);
  }
  player.setX(getPlayerX());
  player.setY(getPlayerY());
  for (unsigned int n = 0; n < gameMap.getRooms().size(); n++) {
    if (gameMap.getRooms().at(gameMap.getNumberRoom()).getX() + move_x == gameMap.getRooms().at(n).getX()) {
      if (gameMap.getRooms().at(gameMap.getNumberRoom()).getY() + move_y == gameMap.getRooms().at(n).getY()) {
        gameMap.setNumberRoom(n);
        gameMap.getCurrentRoom().renderRoom();
        break;
      }
    }
  }
}
void GameLogic::playerMove() {
  if (controls->isUp()) {
    player.setY(player.getY() - player.getSpeed());
    player.addStep();
  }
  if (controls->isDown()) {
    player.setY(player.getY() + player.getSpeed());
    player.addStep();
  }
  if (controls->isLeft()) {
    player.setX(player.getX() - player.getSpeed());
    player.addStep();
  }
  if (controls->isRight()) {
    player.setX(player.getX() + player.getSpeed());
    player.addStep();
  }
  interWall();
}
void GameLogic::interWall() {
  terminal_layer(0);
  if (terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getWallSymbol() ||
      terminal_pick(player.getX(), player.getY(), 0) == gameMap.getCurrentRoom().getDoorSymbol()) {
    player.setX(getPlayerX());
    player.setY(getPlayerY());
    player.removeStep();
  }
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
int GameLogic::getLevel() const {
  return level_;
}
void GameLogic::setLevel(int level) {
  level_ = level;
}
