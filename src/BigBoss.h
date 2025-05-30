// BigBoss.h
#ifndef BIGBOSS_H
#define BIGBOSS_H
#include "Enemy.h"

class BigBoss : public Enemy {

public:
    BigBoss() : Enemy("Gran Jefe", 200, 30, 20,  8,  8) {}
};
#endif