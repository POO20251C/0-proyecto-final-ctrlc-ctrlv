// ScoreManager.cpp
#include "ScoreManager.h"
#include <fstream>
#include <ctime>

void ScoreManager::saveScore(const std::string& playerName, int score, int room, int hpLost) {
    std::ofstream file("scores.txt", std::ios::app);
    std::time_t t = std::time(nullptr);
    file << playerName << ", " << score << ", Room: " << room << ", HP Lost: " << hpLost << ", " << std::ctime(&t);
    file.close();
}
