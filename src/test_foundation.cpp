#include <iostream>
#include "Player.h"

int main() {
    std::cout << "=== COMPREHENSIVE PLAYER CLASS TEST ===\n";
    std::cout << "This test verifies all Player class functionality works correctly.\n\n";

    std::cout << "TEST 1: Player Creation\n";
    std::cout << "Creating a player named 'TestWarrior'...\n";
    Player warrior("TestWarrior");
    std::cout << "Initial status: ";
    warrior.printStatus();
    std::cout << "Expected: 100 HP, 10 ATK, 5 DEF, Alive: Yes\n\n";

    std::cout << "TEST 2: Damage System\n";
    std::cout << "Applying 30 damage to the player...\n";
    warrior.takeDamage(30);
    std::cout << "Status after damage: ";
    warrior.printStatus();
    std::cout << "Expected: 70 HP, 10 ATK, 5 DEF, Alive: Yes\n\n";

    std::cout << "TEST 3: Item System\n";
    std::cout << "Adding a sword (+15 ATK) and armor (+10 DEF)...\n";
    Item sword = {"Iron Sword", 15, 0};
    Item armor = {"Steel Armor", 0, 10};
    warrior.addItem(sword);
    warrior.addItem(armor);
    std::cout << "Status with items: ";
    warrior.printStatus();
    std::cout << "Expected: 70 HP, 25 ATK, 15 DEF, Alive: Yes\n\n";

    std::cout << "TEST 4: Death Condition\n";
    std::cout << "Applying 100 damage (should eliminate player)...\n";
    warrior.takeDamage(100);
    std::cout << "Final status: ";
    warrior.printStatus();
    std::cout << "Expected: 0 HP, 25 ATK, 15 DEF, Alive: No\n\n";

    std::cout << "TEST 5: Dead Player Protection\n";
    std::cout << "Attempting to apply 50 damage to dead player...\n";
    warrior.takeDamage(50);
    std::cout << "No damage should be shown above (player already dead).\n";

    std::cout << "\n=== ALL TESTS COMPLETED ===\n";
    return 0;
}
