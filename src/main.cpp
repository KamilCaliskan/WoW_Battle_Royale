#include <iostream>
#include "Player.h"

int main() {
    std::cout << "WoW Battle Royale Simulation\n";
    std::cout << "=============================\n\n";

    // Create some players
    Player player1("Warrior");
    Player player2("Hunter");
    Player player3("Mage");

    // Show initial status
    std::cout << "Initial Player Status:\n";
    player1.printStatus();
    player2.printStatus();
    player3.printStatus();

    std::cout << "\n--- Simulation Complete ---\n";
    return 0;
}
