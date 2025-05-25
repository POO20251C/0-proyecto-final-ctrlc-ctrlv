// Hero.h
#ifndef HERO_H
#define HERO_H

#include "Character.h"
#include <string>

class Hero : public Character {
public:
    Hero(const std::string& name);
    void attack(Character& target) override;
};

#endif // HERO_H