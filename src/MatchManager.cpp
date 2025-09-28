#include "MatchManager.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

MatchManager::MatchManager() : safeZone(100) {
    tickCount = 0;
}

void MatchManager::addPlayer(Player p) {
    players.push_back(p);
}

void MatchManager::update() {
    tickCount++;
    std::cout << "\nTick " << tickCount << "\n";
    logToFile("Tick " + std::to_string(tickCount));

    // Shrink safe zone every 3 ticks
    if (tickCount % 3 == 0) {
        safeZone.shrink();
        std::cout << "SafeZone shrinks! New radius: " << safeZone.radius << "\n";
        logToFile("SafeZone shrinks! Radius: " + std::to_string(safeZone.radius));
    }

    for (auto &player : players) {
        if (!player.alive) continue;

        // Outside safe zone = damage
        if (safeZone.radius < 70 && rand() % 2 == 0) {
            player.takeDamage(15);
            std::cout << player.name << " took zone damage! HP: " << player.health << "\n";
            logToFile(player.name + " took zone damage! HP: " + std::to_string(player.health));
        }

        // Random combat damage
        if (rand() % 5 == 0) {
            player.takeDamage(20);
            std::cout << player.name << " took combat damage! HP: " << player.health << "\n";
            logToFile(player.name + " took combat damage! HP: " + std::to_string(player.health));
        }

        // Random loot
        if (rand() % 3 == 0) {
            std::string loot = lootManager.getRandomLoot();
            player.addLoot(loot);
            std::cout << player.name << " picked up: " << loot << "\n";
            logToFile(player.name + " picked up: " + loot);
        }
    }
}

bool MatchManager::isMatchOver() {
    int aliveCount = 0;
    for (auto &p : players) {
        if (p.alive) aliveCount++;
    }
    return aliveCount <= 1;
}

void MatchManager::printWinner() {
    for (auto &p : players) {
        if (p.alive) {
            std::cout << "\nWinner: " << p.name << "\nInventory: ";
            logToFile("Winner: " + p.name);
            for (auto &item : p.inventory) {
                std::cout << item << " ";
                logToFile("Item: " + item);
            }
            std::cout << "\n";
        }
    }
}

void MatchManager::logToFile(const std::string &msg) {
    std::ofstream log("battle_log.txt", std::ios::app);
    log << msg << "\n";
    log.close();
}
