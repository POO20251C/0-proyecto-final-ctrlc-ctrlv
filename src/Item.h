// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemType { WEAPON, ARMOR, POTION };

class Item {
public:
    Item(const std::string& name, ItemType type, int value);
    const std::string& getName() const;
    ItemType getType() const;
    int getValue() const;

private:
    std::string name;
    ItemType type;
    int value;
};

#endif // ITEM_H