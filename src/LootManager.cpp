#include "LootSystem.h"
#include <cstdlib>
#include <ctime>

LootSystem::LootSystem() {
    // Initialize available items
    availableItems = {
        {"Sword", 15, 0},
        {"Axe", 20, 0},
        {"Bow", 12, 0},
        {"Armor", 0, 10},
        {"Shield", 0, 8},
        {"Health Potion", 0, 0}  // Special case - handled separately
    };

    // Seed random number generator
    std::srand(std::time(0));
}

Item LootSystem::getRandomItem() {
    int index = std::rand() % availableItems.size();
    return availableItems[index];
}

void LootSystem::distributeStartingLoot(std::vector<Player>& players) {
    for (auto& player : players) {
        // 50% chance to get an item
        if (std::rand() % 2 == 0) {
            Item loot = getRandomItem();
            player.addItem(loot);
        }
    }
}
