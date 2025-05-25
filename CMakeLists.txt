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
        src/Game.h)
