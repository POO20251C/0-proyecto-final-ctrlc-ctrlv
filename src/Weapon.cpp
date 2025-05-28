// Weapon.cpp
#include "Weapon.h"

Weapon::Weapon(const std::string& name, int atk, int lck)
    : Item(name, ItemType::WEAPON, atk), bonusLck(lck) {}

void Weapon::applyEffect(Character& character) {
    character.setAtk(character.getAtk() + getValue());
    character.setLck(character.getLck() + bonusLck);
}
