// Accessory.cpp
#include "Accessory.h"

Accessory::Accessory(const std::string& name, double spd)
    : Item(name, ItemType::ACCESSORY, spd) {}

void Accessory::applyEffect(Character& character) {
    character.setSpd(character.getSpd() + getValue());
}
