#include <BearLibTerminal.h>
#include "../include/player.h"
#include "../include/controls.h"
#include "../include/room.h"

void Player::Move() {
    Room room;
    //движение при нажатии клавиши
    if(controls.IsUp())
        y_ -= speed_;
    if(controls.IsDown())
        y_ += speed_;
    if(controls.IsRight())
        x_ += speed_;
    if(controls.IsLeft())
        x_ -= speed_;

    //ограничения по передвижению по комнате
//    if(GetX() <= 0)
//        x_ = GetX() + 1;
//    if(GetX() >= room.GetRoomSize())
//        x_ = GetX() - 1;
//    if(GetY() <= 0)
//        y_ = GetY() + 1;
//    if(GetY() >= room.GetRoomSize())
//        y_ = GetY() - 1;
}

void Player::Render() {
    terminal_put(x_, y_, symbol_);
}

void Player::Update() {
    Move();
    Render();
}

int Player::GetX() const {
    return x_;
}

int Player::GetY() const {
    return y_;
}

Player::Player(const Controls &controls, int x, int y) : controls(controls), x_(x), y_(y) {
//    terminal_set("0x40: src/tiles/fish_test.png");
}
