// Inventory.cpp
#include "Inventory.h"
#include <iostream>

void Inventory::addItem(std::shared_ptr<Item> item) {
    items.push_back(item);
    std::cout << "Added item: " << item->getName() << "\n";
}

void Inventory::listItems() const {
    std::cout << "Inventory:\n";
    for (const auto& item : items) {
        std::cout << " - " << item->getName() << "\n";
    }
}