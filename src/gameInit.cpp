#include "../include/gameInit.h"
#include "../include/controls.h"
#include "../include/player.h"
#include "../include/map.h"
#include "../include/room.h"
#include "../include/coin.h"

void GameInit::initialize() {
    map.generator();
    map.render(0);
}

void GameInit::update() {
    map.player_x = player.getX();
    map.player_y = player.getY();
    if(controls.isE()){
        map.scanner(player.getX(), player.getY(), map.number_room_);
        player.setX(map.player_x);
        player.setY(map.player_y);
    }
    player.update();
}

GameInit::GameInit(Controls &controls) : controls(controls) {}
