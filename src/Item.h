// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "Character.h"

enum class ItemType { WEAPON, ARMOR, POTION, ACCESSORY, AMULET }; // agregue el quinto item que faltaba definir

class Item {
public:
    Item(const std::string& name, ItemType type, double value);
    virtual ~Item() = default; // para la sobrescritura de las subclases

    const std::string& getName() const;
    ItemType getType() const;
    double getValue() const; // int -> double

    virtual void applyEffect(Character& character) = 0; // aplica el efecto de los items al personaje
    void printInfo() const; // muestra la info

private:
    std::string name;
    ItemType type;
    double value; // ya que los atributos del personaje son double, cambie el tipo de Value por double tambien
};

#endif // ITEM_H