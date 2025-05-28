// Weapon.h
#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Character.h"

class Weapon : public Item {
private:
    int bonusLck;

public:
    Weapon(const std::string& name, int atk, int lck);
    void applyEffect(Character& character) override;
};

#endif // WEAPON_H