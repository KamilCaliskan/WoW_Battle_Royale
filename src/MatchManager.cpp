#include "MatchManager.h"
#include <iostream>

MatchManager::MatchManager() : safeZone(100) {
    tickCount = 0;
}

void MatchManager::addPlayer(Player p) {
    players.push_back(p);
}

void MatchManager::update() {
    tickCount++;
    std::cout << "Tick " << tickCount << "\n";

    // SafeZone shrinks every 2 ticks
    if (tickCount % 2 == 0) {
        safeZone.shrink();
    }

    // Loop through players
    for (auto &player : players) {
        if (!player.alive) continue;

        // Chance player takes damage
        if (rand() % 5 == 0) {
            player.takeDamage(20);
            std::cout << player.name << " took damage! Health: " << player.health << "\n";
        }

        // Chance player finds loot
        if (rand() % 3 == 0) {
            std::string loot = lootManager.getRandomLoot();
            std::cout << player.name << " found loot: " << loot << "\n";
        }
    }
}

bool MatchManager::isMatchOver() {
    int aliveCount = 0;
    for (auto &player : players) {
        if (player.alive) aliveCount++;
    }
    return aliveCount <= 1;
}
