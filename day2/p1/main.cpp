#include <fstream>
#include <iostream>

#define INPUT "input.txt"

int main()
{
    std::ifstream infile{INPUT};

    std::string line;
    while (infile >> line)
    {
        std::cout << line;
    }
}
