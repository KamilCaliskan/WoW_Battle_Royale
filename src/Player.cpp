#include "Player.h"

Player::Player(int playerId, std::string playerName) {
    id = playerId;
    name = playerName;
    health = 100;
    alive = true;
    baseAttack = 8; // baseline damage if no weapon
}

void Player::takeDamage(int amount) {
    if (!alive) return;
    health -= amount;
    if (health <= 0) {
        health = 0;
        alive = false;
    }
}

void Player::addLoot(const Item &item) {
    if (!alive) return;
    inventory.push_back(item);
}

int Player::getAttackPower() const {
    int total = baseAttack;
    for (const auto &it : inventory) total += it.attack;
    return total;
}

int Player::getDefense() const {
    int total = 0;
    for (const auto &it : inventory) total += it.defense;
    return total;
}

void Player::attack(Player &target) {
    if (!alive || !target.alive) return;

    int attackerPower = getAttackPower();
    int targetDef = target.getDefense();

    // Simple formula: baseDamage = attackerPower - (targetDef / 2)
    int damage = attackerPower - (targetDef / 2);
    if (damage < 1) damage = 1;

    // add small random variance [-3..+3]
    damage += (rand() % 7) - 3;
    if (damage < 1) damage = 1;

    target.takeDamage(damage);
}
