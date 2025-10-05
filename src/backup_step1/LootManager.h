#ifndef LOOTMANAGER_H
#define LOOTMANAGER_H

#include <string>
#include <vector>

struct Item {
    std::string name;
    int attack;   // added attack power
    int defense;  // added defense value
    int heal;     // healing amount (if consumable)
};

class LootManager {
public:
    std::vector<Item> lootTable;
    LootManager();
    Item getRandomLoot();
};

#endif // LOOTMANAGER_H
