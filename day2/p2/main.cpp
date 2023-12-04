#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>

typedef std::vector<std::string> StrVector;

StrVector split(std::ifstream& stream, char sep);
StrVector split(const std::string& s, char sep);
int power_of_cube_set(const std::unordered_map<std::string, int>& set);
std::unordered_map<std::string, int> init_cube_set(void);

int main()
{
    std::ifstream infile{"input.txt"};

    uint64_t sum{};

    StrVector games = split(infile, '\n');
    for (const std::string& game : games)
    {
        std::cout << game << '\n';
    }

    std::cout << sum << '\n';
}

StrVector split(std::ifstream& stream, char sep)
{
    StrVector out{};

    std::string token;
    while (std::getline(stream, token, sep))
    {
        out.push_back(token);
    }
    return out;
}

StrVector split(const std::string& s, char sep)
{
    StrVector out{};

    std::stringstream stream{s};
    std::string token;
    while (std::getline(stream, token, sep))
    {
        out.push_back(token);
    }
    return out;
}

int power_of_cube_set(const std::unordered_map<std::string, int>& set)
{
    return set.at("green") * set.at("red") * set.at("blue");
}

std::unordered_map<std::string, int> init_cube_set(void)
{
    std::unordered_map<std::string, int> cube_set;
    cube_set["green"] = 0;
    cube_set["blue"] = 0;
    cube_set["red"] = 0;

    return cube_set;
}
