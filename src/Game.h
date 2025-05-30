// Game.h
#ifndef GAME_H
#define GAME_H

#include "Hero.h"
#include "Enemy.h"
#include "Inventory.h"
#include "ScoreManager.h"
#include <vector>
#include <memory>

class Game {
public:

    Game();
    void run();

private:
    void initHeroPool();    // esto es pa crear los 6 ----> <3
    void chooseHeroes();    // escoger 3
    void initEnemies();
    void showMenu();
    void nextRoom();

    void useItemMenu(); // Para usar items en el personaje
    bool hit(double attackerLuck, double defenderLuck); // relaciona los ataques con la suerte
    double calcularProbAcierto(double attackerLuck, double defenderLuck);

    std::vector<std::shared_ptr<Hero>> heroPool;  // 6
    std::vector<std::shared_ptr<Hero>> heroes;    // 3
    std::vector<std::shared_ptr<Enemy>> enemies;
    Inventory inventory;
    ScoreManager scoreMgr;
    int currentRoom;
    int score;
    int totalHpLost;
};

#endif // GAME_H