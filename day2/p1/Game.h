#pragma once

#include "Hand.h"

#include <string>
#include <vector>

class Game
{
   public:
    Game(const std::string& line);

    bool is_valid(void);
    int id;
    std::vector<Hand> hands;
};
