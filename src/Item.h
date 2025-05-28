// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Character.h"

enum class ItemType { WEAPON, ARMOR, POTION, ACCESSORY, AMULET };

class Item {
public:
    Item(const std::string& name, ItemType type, int value);
    virtual ~Item() = default;

    const std::string& getName() const;
    ItemType getType() const;
    int getValue() const;

    virtual void applyEffect(Character& character) = 0;


private:
    std::string name;
    ItemType type;
    int value;
};

#endif // ITEM_H