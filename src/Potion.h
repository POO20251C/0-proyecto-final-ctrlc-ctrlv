// Potion.h
#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Character.h"

class Potion : public Item {

public:
    Potion(const std::string& name, double hpRestore);
    void applyEffect(Character& character) override;
};


#endif // POTION_H