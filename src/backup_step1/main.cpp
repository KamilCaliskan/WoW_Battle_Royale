#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include "MatchManager.h"

int main(int argc, char* argv[]) {
    // Optional: --seed <num>
    if (argc >= 3 && std::strcmp(argv[1], "--seed") == 0) {
        unsigned int seed = (unsigned int) std::stoul(argv[2]);
        srand(seed);
        std::cout << "Using seed: " << seed << "\n";
    } else {
        srand((unsigned int)time(nullptr));
    }

    std::cout << "WoW Battle Royale Simulation Start!\n";

    // clear previous log
    std::ofstream clear("battle_log.txt", std::ofstream::trunc);
    clear.close();

    MatchManager match;
    match.addPlayer(Player(1, "PlayerOne"));
    match.addPlayer(Player(2, "PlayerTwo"));
    match.addPlayer(Player(3, "PlayerThree"));
    match.addPlayer(Player(4, "PlayerFour"));
    match.addPlayer(Player(5, "PlayerFive"));

    // run ticks (safety limit 100)
    while (!match.isMatchOver() && match.tickCount < 100) {
        match.update();
    }

    std::cout << "\nMatch Ended!\n";
    match.printWinner();

    return 0;
}
