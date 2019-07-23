#include "game/gameInit.h"
#include <BearLibTerminal.h>
#include <cstring>
#include "game/coin.h"
#include "game/controls.h"
#include "game/map.h"
#include "game/player.h"
#include "game/room.h"
#include "game/saver_loader.h"

GameInit::GameInit(Controls* controls) : controls(controls) {}

void GameInit::initializeNew() {
  map = Map();
  map.generator();
  setSprites();
  map.render(0);
}

void GameInit::initializeLoad() {
  player.setCoin(0);
  player.setSteps(0);
  map = Map();
  SaverLoader saverLoader(&map);
  saverLoader.loader();
  for (unsigned int i = 0; i < map.getRooms().size(); i++) {
    map.generateDoor(map.getRooms().at(i).getX(), map.getRooms().at(i).getY(), i);
    map.generateCoin(i);
  }
  setSprites();
  map.render(0);
}

void GameInit::gameMenu() {
  terminal_clear();
  terminal_print(9, 5, "[color=red]Room Escape");
  for (unsigned int i = 0; i < menu.size(); i++) {
    if (getMenuPoint() == static_cast<int>(i)) {
      terminal_color(color_from_name("green"));
    }
    terminal_printf(9, 8 + i, "%s", menu[i]);
    terminal_color(color_from_name("white"));
    if (controls->isEnter()) {
      // продолжить игру
      if (strcmp(menu[getMenuPoint()], continue_game_) == 0) {
        setMenuPoint(10);
        setGameStart(false);
        map.render(map.getNumberRoom());
        break;
      }
      // новая игра
      if (strcmp(menu[getMenuPoint()], new_game_) == 0) {
        setMenuPoint(10);
        initializeNew();
        if (strcmp(menu[0], continue_game_) != 0) setMenu();
        setGameStart(false);
        break;
      }
      // загрузить игру
      if (strcmp(menu[getMenuPoint()], load_game_) == 0) {
        setMenuPoint(0);
        initializeLoad();
        setGameStart(false);
        break;
      }
      // сохранить игру
      if (strcmp(menu[getMenuPoint()], save_game_) == 0) {
        SaverLoader saverLoader(&map);
        setMenuPoint(0);
        saverLoader.saver();
        break;
      }
      // выход
      if (strcmp(menu[getMenuPoint()], end_game_) == 0) {
        setMenuPoint(11);
        break;
      }
    }
  }
  if (controls->isUp()) {
    setMenuPoint(getMenuPoint() - 1);
    if (getMenuPoint() < 0) setMenuPoint(menu.size() - 1);
  }
  if (controls->isDown()) {
    setMenuPoint(getMenuPoint() + 1);
    if (getMenuPoint() > static_cast<int>(menu.size()) - 1) setMenuPoint(0);
  }
  terminal_color(color_from_name("white"));
}

void GameInit::setMenu() {
  menu.insert(menu.begin(), continue_game_);
  menu.insert(menu.begin() + 2, save_game_);
}

void GameInit::loadMenu() {
  terminal_clear();
  terminal_print(9, 5, "[color=red]Сохранения");
}

void GameInit::update() {
  terminal_layer(1);
  terminal_clear_area(1, 1, 19, 19);
  terminal_layer(0);
  terminal_clear_area(1, 1, 19, 19);

  if (gameOver_) {
    endGame();
    return;
  }

  if (isCoinStop()) {
    if (map.getAllCoin() == 0) {
      setCoinStop(false);
      map.getCurrentRoom().setExit(true);
    }
  }
  setGameStart(false);
  map.renderCoin(map.getNumberRoom());
  map.player_x_ = player.getX();
  map.player_y_ = player.getY();
  if (controls->isE()) {
    map.scanner(player.getX(), player.getY(), map.number_room_);
    player.setX(map.player_x_);
    player.setY(map.player_y_);
    if (terminal_pick(player.getX(), player.getY(), 0) == map.getCurrentRoom().getSymbolExit()) {
      gameOver_ = true;
    }
  }

  renderHUD();
  player.update();
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
  if (controls->isEsc()) {
    setGameStart(true);
    setMenuPoint(0);
    gameMenu();
  }
}

void GameInit::renderHUD() {
  terminal_clear_area(21, 0, 7, 20);
  terminal_put(21, 17, 0x40);
  terminal_printf(22, 17, "=%d", player.getSteps());

  terminal_put(21, 19, 0x24);
  terminal_printf(22, 19, "=%d", player.getCoin());
}

void GameInit::endGame() {
  terminal_clear();
  terminal_print(0, 0, "Статистика:");
  terminal_printf(1, 2, "Шагов=%d", player.getSteps());
  terminal_printf(1, 3, "Монет=%d", player.getCoin());
}

void GameInit::setSprites() {
  terminal_set("0x40: ./resources/sprites/player.png");
  terminal_set("0x23: ./resources/sprites/castle.png");
  terminal_set("0x3E: ./resources/sprites/door.png");
  terminal_set("0x25: ./resources/sprites/signExit.png");
  terminal_set("0x24: ./resources/sprites/coinGold.png");
}

bool GameInit::isCoinStop() const {
  return coinStop_;
}
void GameInit::setCoinStop(bool coinStop) {
  GameInit::coinStop_ = coinStop;
}
bool GameInit::isGameStart() const {
  return gameStart_;
}
void GameInit::setGameStart(bool gameStart) {
  gameStart_ = gameStart;
}
int GameInit::getMenuPoint() const {
  return menuPoint;
}
void GameInit::setMenuPoint(int menuPoint) {
  GameInit::menuPoint = menuPoint;
}
