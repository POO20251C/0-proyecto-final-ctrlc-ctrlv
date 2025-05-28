// Weapon.cpp
#include "Weapon.h"

Weapon::Weapon(const std::string& name, double atk, double lck)
    : Item(name, ItemType::WEAPON, atk), bonusLck(lck) {}

void Weapon::applyEffect(Character& character) {
    character.setAtk(character.getAtk() + getValue());
    character.setLck(character.getLck() + bonusLck);
}
