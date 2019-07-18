#include "game/player.h"
#include <BearLibTerminal.h>
#include "game/controls.h"
#include "game/room.h"

void Player::move() {
  // движение при нажатии клавиши
  if (controls.isUp()) {
    y_ -= speed_;
    steps++;
  }
  if (controls.isDown()) {
    y_ += speed_;
    steps++;
  }
  if (controls.isRight()) {
    x_ += speed_;
    steps++;
  }
  if (controls.isLeft()) {
    x_ -= speed_;
    steps++;
  }
  restriction();
}

void Player::render() {
  terminal_put(x_, y_, symbol_);
}

void Player::restriction() {
  Map map;
  //    ограничения по передвижению по комнате
  if (getX() <= 0) {
    setX(getX() + 1);
    setSteps(getSteps() - 1);
  }
  if (getX() >= map.getCurrentRoom().getRoomSize()) {
    setX(getX() - 1);
    setSteps(getSteps() - 1);
  }
  if (getY() <= 0) {
    setY(getY() + 1);
    setSteps(getSteps() - 1);
  }
  if (getY() >= map.getCurrentRoom().getRoomSize()) {
    setY(getY() - 1);
    setSteps(getSteps() - 1);
  }
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
  terminal_set("0x40: ./resources/tiles/player.png");
}

void Player::setX(int x) {
  x_ = x;
}

void Player::setY(int y) {
  y_ = y;
}

int Player::getSteps() const {
  return steps;
}

void Player::setSteps(int steps) {
  Player::steps = steps;
}

int Player::getCoin() const {
  return coin;
}

void Player::setCoin(int coin) {
  Player::coin = coin;
}
