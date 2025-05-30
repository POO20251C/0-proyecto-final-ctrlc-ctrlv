// Accessory.h
#ifndef ACCESSORY_H
#define ACCESSORY_H

#include "Item.h"
#include "Character.h"

class Accessory : public Item {

public:

    Accessory(const std::string& name, double spd);
    void applyEffect(Character& character) override;
};

#endif //ACCESSORY_H
