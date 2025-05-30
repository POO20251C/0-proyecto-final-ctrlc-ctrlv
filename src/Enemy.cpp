// Enemy.cpp
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& type, double  hp, double  atk, double  def, double  lck, double  spd)
    : Character(type, hp, atk, def, lck, spd) {}

void Enemy::attack(Character& target) {
    double  damage = atk - target.getDefense() / 2;
    if (damage < 0) damage = 0;
    target.takeDamage(damage);
    std::cout << name << " strikes " << target.getName() << " for " << damage << " damage.\n";
}

