cmake_minimum_required(VERSION 3.30)
project(ProyectoFinalPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoFinalPOO main.cpp
        src/Character.cpp
        src/Character.h
        src/Hero.cpp
        src/Hero.h
        src/Enemy.cpp
        src/Enemy.h
        src/Item.cpp
        src/Item.h
        src/Inventory.cpp
        src/Inventory.h
        src/ScoreManager.cpp
        src/ScoreManager.h
        src/Game.cpp
        src/Game.h
        src/Soldier.cpp
        src/Soldier.h
        src/MiniBoss.cpp
        src/MiniBoss.h
        src/BigBoss.cpp
        src/BigBoss.h

        src/Weapon.h
        src/Weapon.cpp
        src/Armor.h
        src/Armor.cpp
        src/Potion.h
        src/Potion.cpp
        src/Accessory.h
        src/Accessory.cpp
        src/Amulet.h
        src/Amulet.cpp

)
