#include "Player.h"

Player::Player(int playerId, std::string playerName) {
    id = playerId;
    name = playerName;
    health = 100;
    alive = true;
}

void Player::takeDamage(int amount) {
    if (!alive) return;
    health -= amount;
    if (health <= 0) {
        health = 0;
        alive = false;
    }
}

void Player::addLoot(const std::string &item) {
    if (alive)
        inventory.push_back(item);
}
