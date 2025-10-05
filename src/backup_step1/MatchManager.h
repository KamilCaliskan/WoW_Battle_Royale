#ifndef MATCHMANAGER_H
#define MATCHMANAGER_H

#include "Player.h"
#include "SafeZone.h"
#include "LootManager.h"
#include <vector>

class MatchManager {
public:
    std::vector<Player> players;
    SafeZone safeZone;
    LootManager lootManager;
    int tickCount;

    MatchManager();
    void addPlayer(Player p);
    void update();
    bool isMatchOver();
    void printWinner();
    void logToFile(const std::string &msg);
};

#endif
