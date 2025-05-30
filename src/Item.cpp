// Item.cpp
#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, ItemType type, double value)
    : name(name), type(type), value(value) {}

const std::string& Item::getName() const {
    return name;
}

ItemType Item::getType() const {
    return type;
}

double Item::getValue() const {
    return value; // int -> double
}

// Metodo para mostrar info del item
void Item::printInfo() const {
    std::cout << "Item: " << name << " | Type: ";
    switch (type) {
        case ItemType::WEAPON: std::cout << "Weapon"; break;
        case ItemType::ARMOR: std::cout << "Armor"; break;
        case ItemType::POTION: std::cout << "Potion"; break;
        case ItemType::ACCESSORY: std::cout << "Accessory"; break;
        case ItemType::AMULET: std::cout << "Amulet"; break;
    }
    std::cout << " | Value: " << value << std::endl;
}