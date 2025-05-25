// Hero.cpp
#include "Hero.h"
#include <iostream>

Hero::Hero(const std::string& name)
    : Character(name, 100, 20, 5, 10, 15) {}

void Hero::attack(Character& target) {
    // simple damage formula
    int damage = atk - target.getDefense() / 2;
    if (damage < 0) damage = 0;
    target.takeDamage(damage);
    std::cout << name << " hits " << target.getName() << " for " << damage << " damage.\n";
}