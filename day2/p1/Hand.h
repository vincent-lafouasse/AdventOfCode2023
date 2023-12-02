#pragma once

class Hand
{
   public:
    int red;
    int blue;
    int green;

    bool is_possible(const Hand& maximum);
};
