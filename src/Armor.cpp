// Armor.cpp
#include "Armor.h"

Armor::Armor(const std::string& name, int def, int hp)
    : Item(name, ItemType::ARMOR, def), bonusHp(hp) {}

void Armor::applyEffect(Character& character) {
    character.setDef(character.getDef() + getValue());
    character.setHp(character.getHp() + bonusHp);
}
