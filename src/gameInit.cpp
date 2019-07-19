#include "game/gameInit.h"
#include <BearLibTerminal.h>
#include "game/coin.h"
#include "game/controls.h"
#include "game/map.h"
#include "game/player.h"
#include "game/room.h"

GameInit::GameInit(Controls* controls) : controls(controls) {}

void GameInit::initialize() {
  map.generator();
  terminal_set("0x40: ./resources/sprites/player.png");
  terminal_set("0x23: ./resources/sprites/castle.png");
  terminal_set("0x3E: ./resources/sprites/door.png");
  terminal_set("0x45: ./resources/sprites/signExit.png");
  terminal_set("0x24: ./resources/sprites/coinGold.png");
  map.render(0);
}

void GameInit::gameStart() {
  terminal_clear();
  terminal_print(9, 5, "[color=red]Room Escape");
  for (int i = 0; i < menu.size(); i++) {
    if (getMenuPoint() == i) {
      terminal_color(color_from_name("green"));
    }
    if (controls->isEnter()) {
      if (getMenuPoint() == 0) {
        setMenuPoint(10);
        terminal_color(color_from_name("NULL"));
        initialize();
        setGameStart(false);
      }
      if (getMenuPoint() == 1) terminal_close();
    }
    terminal_printf(9, 8 + i, "%s", menu[i]);
    terminal_color(color_from_name("white"));
  }
  if (controls->isDown()) {
    setMenuPoint(getMenuPoint() + 1);
    if (getMenuPoint() > menu.size() - 1) setMenuPoint(0);
  }
  if (controls->isUp()) {
    setMenuPoint(getMenuPoint() - 1);
    if (getMenuPoint() < 0) setMenuPoint(menu.size() - 1);
  }
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

  map.renderCoin(map.getNumberRoom());
  map.player_x = player.getX();
  map.player_y = player.getY();
  if (controls->isE()) {
    map.scanner(player.getX(), player.getY(), map.number_room_);
    player.setX(map.player_x);
    player.setY(map.player_y);
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
