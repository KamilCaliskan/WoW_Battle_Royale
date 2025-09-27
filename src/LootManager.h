#ifndef LOOTMANAGER_H
#define LOOTMANAGER_H

#include <string>
#include <vector>

class LootManager {
public:
    std::vector<std::string> lootTable;

    LootManager();
    std::string getRandomLoot();
};

#endif
