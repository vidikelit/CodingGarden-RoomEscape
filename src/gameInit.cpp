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
  terminal_set("0x23: ./resources/tiles/castle.png");
  terminal_set("0x3E: ./resources/tiles/door.png");
  terminal_set("0x24: ./resources/tiles/coinGold.png");
  map.render(0);
}

void GameInit::update() {
  map.player_x = player.getX();
  map.player_y = player.getY();
  if (controls->isE()) {
    map.scanner(player.getX(), player.getY(), map.number_room_);
    player.setX(map.player_x);
    player.setY(map.player_y);
  }

  map.render(map.getNumberRoom());
  player.update();
  if (map.getCurrentRoom().getCoinCount() != 0) {
    terminal_layer(1);
    if (terminal_pick(player.getX(), player.getY(), 0) == map.getCurrentRoom().getCoin(0).getSymbolCoin()) {
      for (int i = 0; i < map.getCurrentRoom().getCoinCount(); i++) {
        if (player.getX() == map.getCurrentRoom().getCoin(i).getX() &&
            player.getY() == map.getCurrentRoom().getCoin(i).getY()) {
          map.getCurrentRoom().removeCoin(i);
        }
      }
    }
  }
  //    interaction.update();
}
