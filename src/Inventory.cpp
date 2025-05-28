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

// Usar el item que escoja.
void Inventory::useItem(int index, Character& target) {
    if (index < 0 || index >= static_cast<int>(items.size())) {
        std::cout << "Invalid item index.\n";
        return;
    }
    items[index]->applyEffect(target); // aplica el efecto del item
    std::cout << "Used item: " << items[index]->getName() << " on " << target.getName() << "\n";
    items.erase(items.begin() + index);
}