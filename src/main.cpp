#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MatchManager.h"

int main() {
    srand(time(0)); // random seed

    std::cout << "WoW Battle Royale Simulation Start!\n";

    MatchManager match;

    match.addPlayer(Player(1, "PlayerOne"));
    match.addPlayer(Player(2, "PlayerTwo"));
    match.addPlayer(Player(3, "PlayerThree"));
    match.addPlayer(Player(4, "PlayerFour"));

    while (!match.isMatchOver() && match.tickCount < 10) {
        match.update();
    }

    std::cout << "Match Ended!\n";
    return 0;
}
