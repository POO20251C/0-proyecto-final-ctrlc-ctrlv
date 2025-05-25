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

void Character::increaseAttackPercent(double percent) {
    atk = static_cast<int>(atk * (1.0 + percent / 100.0));
}

void Character::increaseDefensePercent(double percent) {
    def = static_cast<int>(def * (1.0 + percent / 100.0));
}