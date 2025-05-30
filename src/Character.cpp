// Character.cpp
#include "Character.h"


Character::Character(const std::string& name, double  hp, double  atk, double  def, double  lck, double  spd)
    : name(name), hp(hp), atk(atk), def(def), lck(lck), spd(spd) {}

Character::~Character() {}

void Character::takeDamage(double  amount) {
    hp -= amount;
    if (hp < 0) hp = 0;
}

bool Character::isAlive() const {
    return hp > 0;
}

const std::string& Character::getName() const {
    return name;
}

double  Character::getHP() const {
    return hp;
}

double  Character::getDefense() const {
    return def;
}

double  Character::getAttack() const {
    return atk;
}

double  Character::getLuck() const {
    return lck;
}

double  Character::getSpeed() const {
    return spd;
}

void Character::increaseAttackPercent(double percent) {
    atk = static_cast<int>(atk * (1.0 + percent / 100.0));
}

void Character::increaseDefensePercent(double percent) {
    def = static_cast<int>(def * (1.0 + percent / 100.0));
}

// Agregados para que los items tengan efecto

void Character::setHP(double value) {
    hp = value;
}

void Character::setAttack(double value) {
    atk = value;
}

void Character::setDefense(double value) {
    def = value;
}

void Character::setLuck(double value) {
    lck = value;
}

void Character::setSpeed(double value) {
    spd = value;
}




