// Hero.cpp
#include "Hero.h"
#include <iostream>


Hero::Hero(const std::string& name)
    : Character(name, 100, 20, 5, 10, 15) {}

void Hero::attack(Character& target) {
    // Prueba de funcionalidad del ataque en esta clase -> Nota: no funciono
    /*if (!hit(this->getLuck(), target.getLuck())) {
        std::cout << this->getName() << " falla su ataque contra " << target.getName() << "!\n";
        return;
    }*/

    // simple damage formula
    double  damage = atk - target.getDefense() / 2;
    if (damage < 0) damage = 0;
    target.takeDamage(damage);
    std::cout << name << " hits " << target.getName() << " for " << damage << " damage.\n";
}