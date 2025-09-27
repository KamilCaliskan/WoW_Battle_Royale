#include "LootManager.h"
#include <cstdlib>

LootManager::LootManager() {
    lootTable = {"Sword", "Bow", "Potion", "Armor", "Shield"};
}

std::string LootManager::getRandomLoot() {
    int index = rand() % lootTable.size();
    return lootTable[index];
}
