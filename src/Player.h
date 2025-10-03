#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "LootManager.h"

class Player {
public:
    int id;
    std::string name;
    int health;
    bool alive;
    std::vector<Item> inventory;
    int baseAttack;

    Player(int playerId, std::string playerName);
    void takeDamage(int amount);
    void addLoot(const Item &item);
    int getAttackPower() const;
    int getDefense() const;
    void attack(Player &target); // performs an attack against target
};

#endif // PLAYER_H
