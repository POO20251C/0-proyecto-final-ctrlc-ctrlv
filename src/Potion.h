// Potion.h
#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Character.h"

class Potion : public Item {
private:
    double bonusHP;

public:
    Potion(const std::string& name, double hp);
    void applyEffect(Character& character) override;
};


#endif // POTION_H