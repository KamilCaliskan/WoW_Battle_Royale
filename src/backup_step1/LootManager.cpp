#include "LootManager.h"
#include <cstdlib>

LootManager::LootManager() {
    // Simple loot table with basic stats. Expand later.
    lootTable = {
        {"Rusty Sword", 10, 0, 0},
        {"Hunting Bow", 12, 0, 0},
        {"Leather Armor", 0, 8, 0},
        {"Iron Armor", 0, 15, 0},
        {"Small Potion", 0, 0, 25},
        {"Shield", 0, 10, 0},
        {"Battle Axe", 18, 0, 0}
    };
}

Item LootManager::getRandomLoot() {
    int idx = rand() % lootTable.size();
    return lootTable[idx];
}
