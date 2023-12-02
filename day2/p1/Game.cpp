#include "Game.h"

#include <iostream>
#include <sstream>

Game::Game() {}
Game::Game(const std::string& line)
{
	std::stringstream stream{line};
	std::string buffer;

	stream >> buffer;
	stream >> id;
}

bool Game::is_valid(void)
{
    return true;
}

void Game::log(void) const
{
    std::cout << "Id :\t" << id << '\n';

    for (const Hand& hand : hands)
    {
        hand.log();
    }
}
