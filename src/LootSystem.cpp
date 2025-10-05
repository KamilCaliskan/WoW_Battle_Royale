#include "LootSystem.h"
#include <cstdlib>
#include <ctime>

LootSystem::LootSystem() {
    // Initialize the random number generator
    std::srand(std::time(0));

    // Define available items in the game
    availableItems = {
        {"Wooden Sword", 8, 0},
        {"Iron Sword", 15, 0},
        {"Steel Sword", 20, 0},
        {"Leather Armor", 0, 8},
        {"Chainmail Armor", 0, 15},
        {"Plate Armor", 0, 25},
        {"Small Shield", 0, 5},
        {"Tower Shield", 0, 12},
        {"Hunting Bow", 12, 0},
        {"Battle Axe", 18, 0}
    };
}

Item LootSystem::generateRandomItem() {
    int randomIndex = std::rand() % availableItems.size();
    return availableItems[randomIndex];
}

void LootSystem::distributeLoot(Player& player) {
    // 60% chance to get an item
    if (std::rand() % 100 < 60) {
        Item loot = generateRandomItem();
        player.addItem(loot);
    }
}
