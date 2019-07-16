#include <BearLibTerminal.h>
#include "../include/player.h"
#include "../include/controls.h"
#include "../include/room.h"

void Player::interaction() {

}

void Player::move() {
    Room room{0,0};
    //движение при нажатии клавиши
    if(controls.isUp())
        y_ -= speed_;
    if(controls.isDown())
        y_ += speed_;
    if(controls.isRight())
        x_ += speed_;
    if(controls.isLeft())
        x_ -= speed_;

////    ограничения по передвижению по комнате
//    if(getX() <= 0)
//        x_ = getX() + 1;
//    if(getX() >= room.getRoomSize())
//        x_ = getX() - 1;
//    if(getY() <= 0)
//        y_ = getY() + 1;
//    if(getY() >= room.getRoomSize())
//        y_ = getY() - 1;
}

void Player::render() {
    terminal_layer(1);
    terminal_put(x_, y_, symbol_);
    terminal_layer(0);
}

void Player::update() {
    move();
    render();
}

int Player::getX() const {
    return x_;
}

int Player::getY() const {
    return y_;
}

Player::Player(const Controls &controls, int x, int y) : controls(controls), x_(x), y_(y) {
//    terminal_set("0x40: src/tiles/fish_test.png");
}
