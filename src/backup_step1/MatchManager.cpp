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
    std::string t = "Tick " + std::to_string(tickCount);
    std::cout << "\n" << t << "\n";
    logToFile(t);

    // Shrink safe zone every 3 ticks
    if (tickCount % 3 == 0) {
        safeZone.shrink();
        std::string s = "SafeZone shrinks! Radius: " + std::to_string(safeZone.radius);
        std::cout << s << "\n";
        logToFile(s);
    }

    // Attempt loot pickups first
    for (auto &player : players) {
        if (!player.alive) continue;
        if (rand() % 3 == 0) {
            Item loot = lootManager.getRandomLoot();
            player.addLoot(loot);
            std::string s = player.name + " picked up: " + loot.name;
            std::cout << s << "\n";
            logToFile(s);
        }
    }

    // PvP: choose attacker/target pairs
    std::vector<int> aliveIdx;
    for (size_t i = 0; i < players.size(); ++i) if (players[i].alive) aliveIdx.push_back((int)i);

    if (aliveIdx.size() >= 2) {
        // choose number of interactions this tick (1..alive/2)
        int interactions = 1 + (rand() % std::max(1, (int)aliveIdx.size() / 2));
        for (int k = 0; k < interactions; ++k) {
            if (aliveIdx.size() < 2) break;
            int a_i = aliveIdx[rand() % aliveIdx.size()];
            int b_i = a_i;
            while (b_i == a_i) b_i = aliveIdx[rand() % aliveIdx.size()];

            Player &attacker = players[a_i];
            Player &target = players[b_i];

            // chance to attack
            if (rand() % 100 < 70) { // 70% chance attack occurs
                int beforeHP = target.health;
                attacker.attack(target);
                int dmg = beforeHP - target.health;
                std::string s = attacker.name + " attacked " + target.name + " for " + std::to_string(dmg) + " dmg";
                std::cout << s << "\n";
                logToFile(s);
            }
        }
    }

    // Zone damage if zone small: moderate chance
    if (safeZone.radius < 60) {
        for (auto &player : players) {
            if (!player.alive) continue;
            if (rand() % 4 == 0) {
                player.takeDamage(10);
                std::string s = player.name + " takes zone damage. HP: " + std::to_string(player.health);
                std::cout << s << "\n";
                logToFile(s);
            }
        }
    }
}

bool MatchManager::isMatchOver() {
    int aliveCount = 0;
    for (auto &p : players) if (p.alive) aliveCount++;
    return aliveCount <= 1;
}

void MatchManager::printWinner() {
    for (auto &p : players) {
        if (p.alive) {
            std::cout << "\nWinner: " << p.name << "\nInventory: ";
            logToFile("Winner: " + p.name);
            for (auto &it : p.inventory) {
                std::cout << it.name << " ";
                logToFile("Item: " + it.name);
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
