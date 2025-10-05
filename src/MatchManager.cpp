#include "MatchManager.h"
#include <iostream>
#include <cstdlib>

MatchManager::MatchManager() : currentTick(0), matchRunning(false) {
}

void MatchManager::addPlayer(const std::string& name) {
    players.push_back(Player(name));
    std::cout << "Added player: " << name << "\n";
}

void MatchManager::startMatch() {
    if (players.size() < 2) {
        std::cout << "Need at least 2 players to start match!\n";
        return;
    }

    matchRunning = true;
    currentTick = 0;

    std::cout << "\n=== MATCH STARTED ===\n";
    std::cout << "Players: " << players.size() << "\n";

    // Distribute starting loot
    lootSystem.distributeStartingLoot(players);
    std::cout << "Starting loot distributed!\n";
}

void MatchManager::update() {
    if (!matchRunning) return;

    currentTick++;
    std::cout << "\n--- Tick " << currentTick << " ---\n";

    // Process combat every few ticks
    if (currentTick % 2 == 0) {
        processCombat();
    }

    printMatchStatus();
}

void MatchManager::processCombat() {
    std::vector<Player*> alivePlayers;

    // Collect alive players
    for (auto& player : players) {
        if (player.alive) {
            alivePlayers.push_back(&player);
        }
    }

    if (alivePlayers.size() < 2) return;

    // Simple combat: first alive player attacks random other player
    Player* attacker = alivePlayers[0];
    Player* target = nullptr;

    // Find a different alive player to attack
    for (int i = 1; i < alivePlayers.size(); i++) {
        if (alivePlayers[i] != attacker) {
            target = alivePlayers[i];
            break;
        }
    }

    if (attacker && target) {
        int attackPower = attacker->getTotalAttack();
        int defense = target->getTotalDefense();
        int damage = std::max(1, attackPower - defense);

        std::cout << attacker->name << " attacks " << target->name
        << " for " << damage << " damage!\n";

        target->takeDamage(damage);
    }
}

bool MatchManager::isMatchOver() const {
    int aliveCount = 0;
    for (const auto& player : players) {
        if (player.alive) aliveCount++;
    }
    return aliveCount <= 1;
}

void MatchManager::printMatchStatus() const {
    std::cout << "Current Status:\n";
    for (const auto& player : players) {
        player.printStatus();
    }

    if (isMatchOver()) {
        std::cout << "\n=== MATCH OVER ===\n";
        for (const auto& player : players) {
            if
