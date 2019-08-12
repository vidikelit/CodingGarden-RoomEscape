#include "game/player.h"
#include <BearLibTerminal.h>
#include "game/controls.h"

void Player::render() {
  terminal_layer(2);
  terminal_put(x_, y_, symbol_player_);
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
void Player::setX(int x) {
  x_ = x;
}
void Player::setY(int y) {
  y_ = y;
}
int Player::getSpeed() const {
  return speed_;
}
int Player::addStep() {
  return steps_ += 1;
}
int Player::removeStep() {
  return steps_ -= 1;
}
int Player::getSteps() const {
  return steps_;
}
int Player::addCoin() {
  return coin_ += 1;
}
Player::Player(const Controls &controls, int x, int y) : controls(controls), x_(x), y_(y) {}
void Player::setCoin(int coin) {
  coin_ = coin;
}
void Player::setSteps(int steps) {
  steps_ = steps;
}
int Player::getCoin() const {
  return coin_;
}
void Player::setDefault() {
  setX(10);
  setY(11);
  setCoin(0);
  setSteps(0);
}
