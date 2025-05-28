// Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include <vector>
#include <memory>

class Inventory {
public:

    void addItem(std::shared_ptr<Item> item);
    void listItems() const;

    void useItem(int index, Character& target); // usar el item que escoja

private:
    std::vector<std::shared_ptr<Item>> items;
};

#endif // INVENTORY_H