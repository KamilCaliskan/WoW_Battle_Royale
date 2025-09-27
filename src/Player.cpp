#include "Player.h"

Player::Player(int playerId, std::string playerName) {
    id = playerId;
    name = playerName;
    health = 100;
    alive = true;
}

void Player::takeDamage(int amount) {
    health -= amount;
    if (health <= 0) {
        health = 0;
        alive = false;
    }
}
