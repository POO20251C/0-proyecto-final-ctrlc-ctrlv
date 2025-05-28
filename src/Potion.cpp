// Potion.cpp
#include "Potion.h"

Potion::Potion(const std::string& name, double hp)
    : Item(name, ItemType::POTION, hp) {}

void Potion::applyEffect(Character& character) {
    character.setHP(character.getHP() + getValue());
}