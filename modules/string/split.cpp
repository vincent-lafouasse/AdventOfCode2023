#include "string.h"

#include <sstream>

std::vector<std::string> split(std::ifstream& stream, char sep)
{
    std::vector<std::string> out{};

    std::string token;
    while (std::getline(stream, token, sep))
    {
        out.push_back(token);
    }
    return out;
}

std::vector<std::string> split(const std::string& s, char sep)
{
    std::vector<std::string> out{};

    std::stringstream stream{s};
    std::string token;
    while (std::getline(stream, token, sep))
    {
        out.push_back(token);
    }
    return out;
}
