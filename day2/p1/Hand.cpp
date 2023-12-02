#include "Hand.h"

#include <iostream>

bool Hand::is_possible(const Hand& maximum)
{
    return (red <= maximum.red) && (green <= maximum.green) &&
           (blue <= maximum.blue);
}

void Hand::log(void) const
{
    std::cout << "red:\t" << red << '\t';
    std::cout << "green:\t" << green << '\t';
    std::cout << "blue:\t" << blue << '\t';
}
