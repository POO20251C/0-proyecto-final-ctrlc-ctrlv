// Armor.cpp
#include "Armor.h"

Armor::Armor(const std::string& name, double def, double hp)
    : Item(name, ItemType::ARMOR, def), bonusHp(hp) {}

void Armor::applyEffect(Character& character) {
    character.setDefense(character.getDefense() + getValue());
    character.setHP(character.getHP() + bonusHp);
}
