#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

class Player {
public:
    int id;
    std::string name;
    int health;
    bool alive;
    std::vector<std::string> inventory;

    Player(int playerId, std::string playerName);
    void takeDamage(int amount);
    void addLoot(const std::string &item);
};

#endif
