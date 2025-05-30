// Amulet.h

#ifndef AMULET_H
#define AMULET_H

#include "Item.h"
#include "Character.h"

class Amulet : public Item {
private:
    int bonusLck;

public:
    Amulet(const std::string& name, double spd, double lck);
    void applyEffect(Character& character) override;
};

#endif //AMULET_H
