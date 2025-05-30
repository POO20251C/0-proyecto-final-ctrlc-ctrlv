// Game.cpp
#include "Game.h"
#include "Soldier.h"
#include "MiniBoss.h"
#include "BigBoss.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>
#include <iomanip>  // para std::fixed y std::setprecision

#include "Potion.h"
#include "Weapon.h"
#include "Amulet.h"
#include "Accessory.h"
#include "Armor.h"
#include <cstdlib>  // rand()
#include <ctime>    // time()

Game::Game() : currentRoom(1), score(0), totalHpLost(0) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    initHeroPool();    // 6
    chooseHeroes();    // 3
    initEnemies();

    // Crear ítems iniciales
    inventory.addItem(std::make_shared<Potion>("Small Potion", 20));
    inventory.addItem(std::make_shared<Weapon>("Iron Sword", 5, 2));
    inventory.addItem(std::make_shared<Amulet>("Lucky Charm", 3, 4));
}
//______________________________________________________________________________________________
void Game::useItemMenu() { // Usar items

    if (inventory.isEmpty()) {    // No puede usar items si esta vacio el inventario
        std::cout << "No hay ítems en el inventario.\n";
        return;
    }
    inventory.listItems();
    std::cout << "Seleccione el ítem: ";
    int itemIndex;
    std::cin >> itemIndex;

    std::cout << "Seleccione el héroe:";    // Modificado para mostrar todos los atributos del heroe
    for (size_t i = 0; i < heroes.size(); ++i) {
        std::cout << i << ": " << heroes[i]->getName()
                  << " | HP: " << heroes[i]->getHP()
                  << " | ATK: " << heroes[i]->getAttack()
                  << " | DEF: " << heroes[i]->getDefense()
                  << " | LCK: " << heroes[i]->getLuck()
                  << " | SPD: " << heroes[i]->getSpeed() << "\n";
    }
    int heroIndex;
    std::cin >> heroIndex;

    if (heroIndex < 0 || heroIndex >= static_cast<int>(heroes.size())) {
        std::cout << "Índice de héroe inválido.\n";
        return;
    }
    inventory.useItem(itemIndex, *heroes[heroIndex]);
}
// Para la jugabilidad de la suerte -> devuelve true si el golpe acierta, false si falla
bool Game::hit(double attackerLuck, double defenderLuck) {
    double hitProbability = attackerLuck - defenderLuck;
    if (hitProbability > 95.0)
        hitProbability = 95.0; // Para que nunca haya un 100% ni un 0%
    if (hitProbability < 5.0)
        hitProbability = 5.0;
    double roll = static_cast<double>(rand() % 100) + 1; // Random 1-100
    return roll <= hitProbability; // true o false, y llega al ataque
}

double Game::calcularProbAcierto(double attackerLuck, double defenderLuck) {
    double chance = 50.0 + (attackerLuck - defenderLuck);
    if (chance > 95.0) chance = 95.0;
    if (chance < 5.0)  chance = 5.0;
    return chance;
}

//______________________________________________________________________________________

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
    enemies.clear();

    // 10 soldados
    for (int i = 0; i < 10; ++i)
        enemies.push_back(std::make_shared<Soldier>());

    //  3 mini jefes (siempre)
    for (int i = 0; i < 3; ++i)
        enemies.push_back(std::make_shared<MiniBoss>());

    //  2 grandes jefes
    for (int i = 0; i < 2; ++i)
        enemies.push_back(std::make_shared<BigBoss>());
}

void Game::showMenu() {
    std::cout << "\n=== Natal Combat ===\n"
              << "1. Show Heroes\n"
              << "2. Proceed to Next Room\n"
              << "3. Show Inventory\n"
              << "4. Use Item\n" // Agregado para usar los items
              << "5. Exit\n"
              << "Choose an option: ";

}



void Game::nextRoom() {
    if (currentRoom > 10) {
        std::cout << "You have cleared all rooms! Final score: " << score << "\n";
        return;
    }
    std::cout << "Entering Room " << currentRoom << "...\n";

        // Preambulo para las salas especiales
    std::cout << "\n=== Welcome to " << currentRoom << " ===\n";
    if (currentRoom == 1) std::cout << "Starting Market\n";
    if (currentRoom == 3) std::cout << "Enigmatic Chest\n";
    if (currentRoom == 6) std::cout << "Treasure Room\n";
    if (currentRoom == 8) std::cout << "Holy Grail\n";

    // Seleccionar el próximo héroe vivo
    std::shared_ptr<Hero> currentHero = nullptr;
    for (auto& h : heroes) {
        if (h->isAlive()) {
            currentHero = h;
            break;
        }
    }
    if (!currentHero) {
        std::cout << "Todos tus heroes han caído. Game Over.\n";
        return;
    }

    // Guardar HP inicial para calcular HP perdido
    double hpBefore = currentHero->getHP();

    // Selección de enemigo según la sala
    std::shared_ptr<Enemy> enemy;
    if (currentRoom == 8) {
        // Sala 8: siempre Mini Jefe
        enemy = std::make_shared<MiniBoss>();
    }
    else if (currentRoom == 10) {
        // Sala final (10): siempre Gran Jefe
        enemy = std::make_shared<BigBoss>();
    }
    else {
        // Otras salas: del pool de 15 enemigos
        enemy = enemies[(currentRoom - 1) % enemies.size()];
    }

    // Combate por turnos
    /*while (enemy->isAlive() && currentHero->isAlive()) {
        currentHero->attack(*enemy);
        if (!enemy->isAlive()) break;
        enemy->attack(*currentHero);
    }*/

    // Combate por turnos modificado
    /*while (enemy->isAlive() && currentHero->isAlive()) {

        std::cout << "\n=== COMBAT ===\n";                 // Me muestra el estado del combate
        std::cout << currentHero->getName() << " (HP: " << currentHero->getHP()
                  << ")  vs  " << enemy->getName() << " (HP: " << enemy->getHP() << ")\n";


        // Mostrar HP antes del ataque del héroe
        std::cout << "\n[HP Antes del Ataque] "
                  << currentHero->getName() << ": " << currentHero->getHP() << " | "
                  << "Enemy: " << enemy->getHP() << "\n";

        // ----> Prueba para aplicar la probabilidad de ataque con la suerte
        if (hit(currentHero->getLuck(), enemy->getLuck())) {
            currentHero->attack(*enemy);
        } else {
            std::cout << currentHero->getName() << " missed the attack!\n";
        }

        // Mostrar HP después del ataque del héroe
        std::cout << "[HP Despues del Ataque] "
                  << currentHero->getName() << ": " << currentHero->getHP() << " | "
                  << "Enemy: " << enemy->getHP() << "\n";

        if (!enemy->isAlive()) break;

        // Mostrar HP antes del ataque del enemigo
        std::cout << "\n[HP Antes del Ataque] "
                  << currentHero->getName() << ": " << currentHero->getHP() << " | "
                  << "Enemy: " << enemy->getHP() << "\n";

        if (hit(enemy->getLuck(), currentHero->getLuck())) {
            enemy->attack(*currentHero);
        } else {
            std::cout << enemy->getName() << " missed the attack!\n";
        }

        // Mostrar HP después del ataque del enemigo
        std::cout << "[HP Despues del Ataque] "
                  << currentHero->getName() << ": " << currentHero->getHP() << " | "
                  << "Enemigo: " << enemy->getHP() << "\n";
    }*/
    while (enemy->isAlive() && currentHero->isAlive()) {
        std::cout << "\n=== COMBAT ===\n";
        std::cout << currentHero->getName() << " (HP: " << currentHero->getHP()
                  << ")  vs  " << enemy->getName() << " (HP: " << enemy->getHP() << ")\n";

        // Hero's turn
        double probHero = calcularProbAcierto(currentHero->getLuck(), enemy->getLuck());
        std::cout << "Chance to hit (" << currentHero->getName() << " attacking): " << probHero << "%\n";
        if (hit(currentHero->getLuck(), enemy->getLuck())) {
            currentHero->attack(*enemy);
        } else {
            std::cout << currentHero->getName() << " missed the attack!\n";
        }

        std::cout << currentHero->getName() << " HP: " << currentHero->getHP()
                  << " | " << enemy->getName() << " HP: " << enemy->getHP() << "\n";

        if (!enemy->isAlive()) break;

        // Enemy's turn
        double probEnemy = calcularProbAcierto(enemy->getLuck(), currentHero->getLuck());
        std::cout << "\nChance to hit (" << enemy->getName() << " attacking): " << probEnemy << "%\n";
        if (hit(enemy->getLuck(), currentHero->getLuck())) {
            enemy->attack(*currentHero);
        } else {
            std::cout << enemy->getName() << " missed the attack!\n";
        }

        std::cout << currentHero->getName() << " HP: " << currentHero->getHP()
                  << " | " << enemy->getName() << " HP: " << enemy->getHP() << "\n";
    }

    // Calcular HP perdido y actualizar score
    double hpLost = hpBefore - currentHero->getHP();
    totalHpLost += hpLost;                              // REVISAR AQUI PENDIENTE
    score += 10;
    std::cout << "Room " << currentRoom << " cleared! ("
              << currentHero->getName()
              << " perdio " << hpLost << " HP)\n";

    // aqui es donde aumenta ese 2%
    for (auto& h : heroes) {
        if (h->isAlive()) {
            h->increaseAttackPercent(2.0);   // +2% ATK
            h->increaseDefensePercent(2.0);  // +2% DEF
        }
    }


    // Asignacion de items a las salas correspondientes
    if (currentRoom == 3) {
        std::cout << "Recompensa disponible: \n"
                     "1. Accesorio (+2 LCK)\n"
                     "2. 3 Pociones (+25 HP cada una)\n"
                     "Elige una opcion (1 o 2): ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            inventory.addItem(std::make_shared<Accessory>("Silver Ring", 2));
            std::cout << "Has recibido un Silver Ring (+2 LCK).\n";
        } else {
            for (int i = 0; i < 3; ++i) {
                inventory.addItem(std::make_shared<Potion>("Healing Potion", 25));
            }
            std::cout << "Has recibido 3 Healing Potions (+25 HP cada una).\n";
        }
    }
    else if (currentRoom == 6) {
        for (auto& h : heroes) {
            inventory.addItem(std::make_shared<Weapon>("Rare Blade", 8, 5));
        }
        std::cout << "Recompensa: Cada heroe recibio un arma rara (+8 ATK, +5 LCK)!\n";
    }
    else if (currentRoom == 8) {
        for (auto& h : heroes) {
            h->setHP(100);
        }
        std::cout << "El Santo Grial ha restaurado completamente la salud de tus heroes!\n";
    }
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
                    std::cout << h->getName()
                      << " | HP: "  << std::fixed << std::setprecision(1) << h->getHP()
                      << " | ATK: " << h->getAttack()
                      << " | DEF: " << h->getDefense()
                      << " | LCK: " << h->getLuck()
                      << " | SPD: " << h->getSpeed()
                      << std::defaultfloat << "\n";
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
            case 4: // Agregado para usar un item
                useItemMenu();
                break;
            case 5:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    }
}