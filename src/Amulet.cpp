// Amulet.cpp

#include "Amulet.h"

Amulet::Amulet(const std::string& name, double spd, double lck)
    : Item(name, ItemType::AMULET, spd), bonusLck(lck) {}

void Amulet::applyEffect(Character& character) {
    character.setSpeed(character.getSpeed() + getValue());
    character.setLuck(character.getLuck() + bonusLck);
}

