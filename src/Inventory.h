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
private:
    std::vector<std::shared_ptr<Item>> items;
};

#endif // INVENTORY_H