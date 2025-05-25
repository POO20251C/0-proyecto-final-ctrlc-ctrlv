// Enemy.cpp
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(const std::string& type, int hp, int atk, int def, int lck, int spd)
    : Character(type, hp, atk, def, lck, spd) {}

void Enemy::attack(Character& target) {
    int damage = atk - target.getDefense() / 2;
    if (damage < 0) damage = 0;
    target.takeDamage(damage);
    std::cout << name << " strikes " << target.getName() << " for " << damage << " damage.\n";
}