#include <BearLibTerminal.h>
#include "../include/gameInit.h"
#include "../include/controls.h"
#include "../include/player.h"
#include "../include/map.h"
#include "../include/room.h"
#include "../include/coin.h"

void GameInit::initialize() {
    map.generator();
    terminal_set("0x23: ./src/tiles/castle.png");
    terminal_set("0x3E: ./src/tiles/door.png");
    terminal_set("0x24: ./src/tiles/coinGold.png");
    map.render(0);
}

void GameInit::update() {
    map.player_x = player.getX();
    map.player_y = player.getY();
    if (controls.isE()) {
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

GameInit::GameInit(Controls &controls) : controls(controls) {}

