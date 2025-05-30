// MiniBoss.h
#ifndef MINIBOSS_H
#define MINIBOSS_H
#include "Enemy.h"
class MiniBoss : public Enemy {
public:
    MiniBoss() : Enemy("Mini Jefe", 100, 20, 10, 10, 10) {}
};
#endif