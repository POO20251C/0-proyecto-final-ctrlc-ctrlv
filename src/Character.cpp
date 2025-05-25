// Character.cpp
#include "Character.h"

Character::Character(const std::string& name, int hp, int atk, int def, int lck, int spd)
    : name(name), hp(hp), atk(atk), def(def), lck(lck), spd(spd) {}

Character::~Character() {}

void Character::takeDamage(int amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
}

bool Character::isAlive() const {
    return hp > 0;
}

const std::string& Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

int Character::getDefense() const {
    return def;
}

int Character::getAttack() const {
    return atk;
}

int Character::getLuck() const {
    return lck;
}

int Character::getSpeed() const {
    return spd;
}