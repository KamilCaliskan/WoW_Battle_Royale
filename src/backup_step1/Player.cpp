#include "Player.h"
#include <iostream>

Player::Player(const std::string& playerName)
: name(playerName), health(100), baseAttack(10), baseDefense(5), alive(true) {
}

void Player::takeDamage(int damage) {
    if (!alive) return;

    health -= damage;
    std::cout << name << " takes " << damage << " damage. HP: " << health << "\n";

    if (health <= 0) {
        health = 0;
        alive = false;
        std::cout << name << " has been eliminated!\n";
    }
}

void Player::addItem(const Item& item) {
    inventory.push_back(item);
    std::cout << name << " picked up: " << item.name << "\n";
}

int Player::getTotalAttack() const {
    int total = baseAttack;
    for (const auto& item : inventory) {
        total += item.attackBonus;
    }
    return total;
}

int Player::getTotalDefense() const {
    int total = baseDefense;
    for (const auto& item : inventory) {
        total += item.defenseBonus;
    }
    return total;
}

void Player::printStatus() const {
    std::cout << name << " | HP: " << health
    << " | ATK: " << getTotalAttack()
    << " | DEF: " << getTotalDefense()
    << " | Alive: " << (alive ? "Yes" : "No") << "\n";
}
