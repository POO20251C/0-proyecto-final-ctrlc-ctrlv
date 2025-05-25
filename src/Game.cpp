// Game.cpp
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>


Game::Game() : currentRoom(1), score(0), totalHpLost(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    initHeroPool();    // 6
    chooseHeroes();    // 3
    initEnemies();
}

void Game::initHeroPool() {
    heroPool.clear();
    heroPool.push_back(std::make_shared<Hero>("Archer"));
    heroPool.push_back(std::make_shared<Hero>("Warrior"));
    heroPool.push_back(std::make_shared<Hero>("Mage"));
    heroPool.push_back(std::make_shared<Hero>("Rogue"));
    heroPool.push_back(std::make_shared<Hero>("Cleric"));
    heroPool.push_back(std::make_shared<Hero>("Paladin"));
}

void Game::chooseHeroes() {
    // Configurar números aleatorios
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // Barajar el pool de héroes
    std::shuffle(heroPool.begin(), heroPool.end(), gen);
    heroes.assign(heroPool.begin(), heroPool.begin() + 3); //tomar 2 primeros despues de shuffle

    // Mostrar selección
    std::cout << "\nHeroes seleccionados aleatoriamente:\n";
    for (auto& h : heroes) {
        std::cout << " - " << h->getName()
                  << " | HP: "   << h->getHP()
                  << " | ATK: "  << h->getAttack()
                  << " | DEF: "  << h->getDefense()
                  << " | LCK: "  << h->getLuck()
                  << " | SPD: "  << h->getSpeed()
                  << "\n";
    }
}

void Game::initEnemies() {
    for (int i = 0; i < 15; ++i) {
        enemies.push_back(std::make_shared<Enemy>("Goblin", 50, 10, 3, 5, 15));
    }
}

void Game::showMenu() {
    std::cout << "\n=== Natal Combat ===\n"
              << "1. Show Heroes\n"
              << "2. Proceed to Next Room\n"
              << "3. Show Inventory\n"
              << "4. Exit\n"
              << "Choose an option: ";
}


void Game::nextRoom() {
    if (currentRoom > 10) {
        std::cout << "You have cleared all rooms! Final score: " << score << "\n";
        return;
    }
    std::cout << "Entering Room " << currentRoom << "...\n";

    // Seleccionar el próximo héroe vivo
    std::shared_ptr<Hero> currentHero = nullptr;
    for (auto& h : heroes) {
        if (h->isAlive()) {
            currentHero = h;
            break;
        }
    }
    if (!currentHero) {
        std::cout << "Todos tus héroes han caído. Game Over.\n";
        return;
    }

    int hpBefore = currentHero->getHP();

    auto enemy = enemies[(currentRoom - 1) % enemies.size()];
    while (enemy->isAlive() && currentHero->isAlive()) {
        currentHero->attack(*enemy);
        if (!enemy->isAlive()) break;
        enemy->attack(*currentHero);
    }

    int hpLost = hpBefore - currentHero->getHP();
    totalHpLost += hpLost;
    score += 10;
    std::cout << "Room " << currentRoom << " cleared! ("
              << currentHero->getName()
              << " perdio " << hpLost << " HP)\n";

    currentRoom++;
}


void Game::run() {
    bool running = true;
    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "\n-- Heroes Status --\n";
                for (auto& h : heroes)
                    std::cout
                        << h->getName()
                        << " | HP: " << h->getHP()
                        << " | ATK: " << h->getAttack()
                        << " | DEF: " << h->getDefense()
                        << " | LCK: " << h->getLuck()
                        << " | SPD: " << h->getSpeed()
                        << "\n";
                break;
            case 2:
                nextRoom();
                if (currentRoom > 10) {
                    scoreMgr.saveScore(heroes[0]->getName(), score, currentRoom-1, totalHpLost);
                    running = false;
                }
                break;
            case 3:
                inventory.listItems();
                break;
            case 4:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}