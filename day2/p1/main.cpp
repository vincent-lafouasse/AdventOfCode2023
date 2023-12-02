#include <fstream>
#include <iostream>

#include "Game.h"

#define INPUT "input.txt"

int main()
{
    std::ifstream infile{INPUT};

	uint64_t sum{};
	Game current_game;

    std::string line;
    while (getline(infile, line))
    {
        current_game = Game(line);
		current_game.log();
    }
}
