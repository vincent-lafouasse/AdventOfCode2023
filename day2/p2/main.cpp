#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>


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

int main()
{
    std::ifstream infile{"input.txt"};

    uint64_t sum{};

    std::string game;
    while (getline(infile, game))
    {
		std::cout << game.substr(game.find(": ") + 2) << '\n';
		sum += power_of_cube_set(game.substr(game.find(": ") + 2));
    }

    std::cout << sum << '\n';
}
