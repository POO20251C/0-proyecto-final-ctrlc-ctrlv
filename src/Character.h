// == Character.h ==
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    Character(const std::string& name, double hp, double atk, double def, double lck, double spd);
    virtual ~Character();

    virtual void attack(Character& target) = 0;
    void takeDamage(double amount);

    bool    isAlive()   const;
    const std::string& getName()    const;
    double  getHP()      const;
    double  getAttack()  const;
    double  getDefense() const;
    double  getLuck()    const;
    double  getSpeed()   const;

    void increaseAttackPercent(double percent);
    void increaseDefensePercent(double percent);

    // Para que tengan efecto los items
    void setHP(double hp); // void -> double para una prueba
    void setAttack(double atk);
    void setDefense(double def);
    void setLuck(double lck);
    void setSpeed(double spd);




protected:
    std::string name;
    double      hp;   // ahora double
    double      atk;  // ahora double
    double      def;  // ahora double
    double      lck;  // ahora double
    double      spd;  // ahora double
};


#endif // CHARACTER_H
