#include "game/player.h"
#include <BearLibTerminal.h>
#include "game/controls.h"

void Player::render() {
  terminal_layer(2);
  terminal_put(x_, y_, symbol_);
}
void Player::update() {
  render();
}

int Player::getX() const {
  return x_;
}

int Player::getY() const {
  return y_;
}

Player::Player(const Controls &controls, int x, int y) : controls(controls), x_(x), y_(y) {}

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
int Player::getSpeed() const {
  return speed_;
}
void Player::setSpeed(int speed) {
  speed_ = speed;
}
