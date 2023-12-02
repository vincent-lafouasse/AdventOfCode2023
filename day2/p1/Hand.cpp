#include "Hand.h"

bool Hand::is_possible(const Hand& maximum)
{
    return (red <= maximum.red) && (green <= maximum.green) &&
           (blue <= maximum.blue);
}
