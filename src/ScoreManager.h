// ScoreManager.h
#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <string>

class ScoreManager {
public:
    void saveScore(const std::string& playerName, int score, int room, int hpLost);
};

#endif // SCOREMANAGER_H