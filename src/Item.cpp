// Item.cpp
#include "Item.h"

Item::Item(const std::string& name, ItemType type, double value)
    : name(name), type(type), value(value) {}

const std::string& Item::getName() const { return name; }
ItemType Item::getType() const { return type; }
double Item::getValue() const { return value; } // int -> double