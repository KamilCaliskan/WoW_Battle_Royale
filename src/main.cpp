#include <iostream>
#include <ctime>
#include <cstdlib>
#include "MatchManager.h"

int main() {
    srand(time(0));

    std::cout << "WoW Battle Royale Simulation Start!\n";

    MatchManager match;
    match.addPlayer(Player(1, "PlayerOne"));
    match.addPlayer(Player(2, "PlayerTwo"));
    match.addPlayer(Player(3, "PlayerThree"));
    match.addPlayer(Player(4, "PlayerFour"));

    while (!match.isMatchOver() && match.tickCount < 20) {
        match.update();
    }

    std::cout << "\nMatch Ended!\n";
    match.printWinner();

    return 0;
}
