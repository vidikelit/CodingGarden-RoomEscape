#include <BearLibTerminal.h>
#include "../include/player.h"
#include "../include/controls.h"

void Player::Move() {
    if(controls.IsUp())
        y_ -= speed_;
    if(controls.IsDown())
        y_ += speed_;
    if(controls.IsRight())
        x_ += speed_;
    if(controls.IsLeft())
        x_ -= speed_;
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
//    terminal_set("0xE64: ../src/tiles/fish_test.png");
}
