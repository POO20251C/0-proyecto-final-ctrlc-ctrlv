// Soldier.h
#ifndef SOLDIER_H
#define SOLDIER_H
#include "Enemy.h"
class Soldier : public Enemy {
public:
    Soldier() : Enemy("Soldado",  50, 10,  3,  5, 12) {}
};
#endif