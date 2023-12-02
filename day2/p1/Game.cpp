#include "Game.h"

#include <iostream>

Game::Game(const std::string& line) {}

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
