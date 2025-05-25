// Character.h
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    Character(const std::string& name, int hp, int atk, int def, int lck, int spd);
    virtual ~Character();

    virtual void attack(Character& target) = 0;
    void takeDamage(int amount);

    bool isAlive() const;
    const std::string& getName() const;
    // Getters de atributos
    int getHP() const;
    int getDefense() const;
    int getAttack()  const;
    int getLuck()    const;
    int getSpeed()   const;

    void increaseAttackPercent(double percent); //aumenta 2%
    void increaseDefensePercent(double percent); //aumenta 2%

protected:
    std::string name;
    int hp;
    int atk;
    int def;
    int lck;
    int spd;
};

#endif // CHARACTER_H