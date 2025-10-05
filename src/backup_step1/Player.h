#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

struct Item {
    std::string name;
    int attackBonus;
    int defenseBonus;
};

class Player {
public:
    std::string name;
    int health;
    int baseAttack;
    int baseDefense;
    bool alive;
    std::vector<Item> inventory;

    Player(const std::string& playerName);

    void takeDamage(int damage);
    void addItem(const Item& item);
    int getTotalAttack() const;
    int getTotalDefense() const;
    void printStatus() const;
};

#endif
