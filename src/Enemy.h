// Enemy.h
#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <string>

class Enemy : public Character {
public:
    Enemy(const std::string& type, double  hp, double  atk, double  def, double  lck, double  spd);
    void attack(Character& target) override;
};

#endif // ENEMY_H