#ifndef LOOTSYSTEM_H
#define LOOTSYSTEM_H

#include "Player.h"
#include <vector>

class LootSystem {
private:
    std::vector<Item> availableItems;

public:
    LootSystem();
    Item generateRandomItem();
    void distributeLoot(Player& player);
};

#endif
