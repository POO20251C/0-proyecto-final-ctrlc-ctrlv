// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>

class Enemy : public Character {
public:
    Enemy(const std::string& type, int hp, int atk, int def, int lck, int spd);
    void attack(Character& target) override;
};

#endif // ENEMY_H