// Armor.h
#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include "Character.h"

class Armor : public Item {
private:
    int bonusHp;

public:

    Armor(const std::string& name, int def, int hp);
    void applyEffect(Character& character) override;
};

#endif // ARMOR_H