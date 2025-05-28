// Potion.cpp
#include "Potion.h"

Potion::Potion(const std::string& name, int hpRestore)
    : Item(name, ItemType::POTION, hpRestore) {}

void Potion::applyEffect(Character& character) {
    character.setHp(character.getHp() + getValue());
}