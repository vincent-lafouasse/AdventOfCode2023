#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <unordered_map>
#include <vector>

typedef std::vector<std::string> StrVector;

StrVector split(std::ifstream& stream, char sep);
StrVector split(const std::string& s, char sep);
int power_of_cube_set(const std::unordered_map<std::string, int>& set);
std::unordered_map<std::string, int> init_cube_set(void);

void update_set(std::unordered_map<std::string, int>& cube_set,
                const std::string& hand) {
    std::unordered_map<std::string, int> this_set = init_cube_set();

    StrVector draws = split(hand, ',');
    for (const std::string& draw : draws) {
        int n;
        char color[1024];
        sscanf(draw.c_str(), " %d %s ", &n, color);
        this_set[color] += n;
    }

    for (auto it = cube_set.begin(); it != cube_set.end(); it++) {
        cube_set[it->first] =
            std::max(cube_set[it->first], this_set[it->first]);
    }
}

uint64_t game_to_power_set(const std::string& game) {
    std::unordered_map<std::string, int> cube_set = init_cube_set();

    StrVector hands = split(game.substr(game.find(':') + 2), ';');
    for (const std::string& hand : hands) {
        update_set(cube_set, hand);
    }

    return power_of_cube_set(cube_set);
}

int main() {
    std::ifstream infile{"input.txt"};

    StrVector games = split(infile, '\n');

    uint64_t sum{};

    for (const std::string& game : games) {
        sum += game_to_power_set(game);
    }

    std::cout << sum;
}

StrVector split(std::ifstream& stream, char sep) {
    StrVector out{};

    std::string token;
    while (std::getline(stream, token, sep)) {
        out.push_back(token);
    }
    return out;
}

StrVector split(const std::string& s, char sep) {
    StrVector out{};

    std::stringstream stream{s};
    std::string token;
    while (std::getline(stream, token, sep)) {
        out.push_back(token);
    }
    return out;
}

int power_of_cube_set(const std::unordered_map<std::string, int>& set) {
    return set.at("green") * set.at("red") * set.at("blue");
}

std::unordered_map<std::string, int> init_cube_set(void) {
    std::unordered_map<std::string, int> cube_set;
    cube_set["green"] = 0;
    cube_set["blue"] = 0;
    cube_set["red"] = 0;

    return cube_set;
}
