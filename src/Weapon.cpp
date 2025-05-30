// Weapon.cpp
#include "Weapon.h"

Weapon::Weapon(const std::string& name, double atk, double lck)
    : Item(name, ItemType::WEAPON, atk), bonusLck(lck) {}

void Weapon::applyEffect(Character& character) {
    character.setAttack(character.getAttack() + getValue());
    character.setLuck(character.getLuck() + bonusLck);
}
