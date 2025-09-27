#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
public:
    int id;
    std::string name;
    int health;
    bool alive;

    Player(int playerId, std::string playerName);
    void takeDamage(int amount);
};

#endif
