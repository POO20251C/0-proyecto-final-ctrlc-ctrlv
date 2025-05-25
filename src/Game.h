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
    void initHeroes();
    void initEnemies();
    void showMenu();
    void nextRoom();

    std::vector<std::shared_ptr<Hero>> heroes;
    std::vector<std::shared_ptr<Enemy>> enemies;
    Inventory inventory;
    ScoreManager scoreMgr;
    int currentRoom;
    int score;
    int totalHpLost;
};

#endif // GAME_H