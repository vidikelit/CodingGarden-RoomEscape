#include "game/enemy.h"
#include <BearLibTerminal.h>
void Enemy::update() {}
void Enemy::render() {
  terminal_put(x_ + speed_, y_ + speed_, symbol_enemy_);
}
