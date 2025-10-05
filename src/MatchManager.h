#ifndef MATCHMANAGER_H
#define MATCHMANAGER_H

#include "Player.h"
#include "LootSystem.h"
#include <vector>

class MatchManager {
private:
    std::vector<Player> players;
    LootSystem lootSystem;
    int currentTick;
    bool matchRunning;

public:
    MatchManager();

    void addPlayer(const std::string& name);
    void startMatch();
    void update();
    void processCombat();
    bool isMatchOver() const;
    void printMatchStatus() const;
};

#endif
