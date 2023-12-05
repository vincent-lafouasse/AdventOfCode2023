#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

const std::unordered_map<std::string, int> MAX = {
    {"red", 12},
    {"green", 13},
    {"blue", 14},
};

static size_t n_digits(unsigned n) {
    size_t n_digits{};

    while (n) {
        n /= 10;
        n_digits++;
    }
    return n_digits;
}

static bool hand_is_valid(const std::string& hand) {
    std::stringstream stream{hand};

    std::unordered_map<std::string, int> colors;

    char color[1024];
    int n;

    std::string draw;
    while (std::getline(stream, draw, ',')) {
        std::sscanf(draw.c_str(), " %i %s", &n, color);
        std::string color_s = color;
        colors[color_s] += n;
        if (colors[color_s] > MAX.at(color_s))
            return false;
    }
    return true;
}

static bool game_is_valid(const std::string& game) {
    std::stringstream stream{game};

    std::string hand;
    while (std::getline(stream, hand, ';')) {
        if (!hand_is_valid(hand))
            return false;
    }

    return true;
}

int main() {
    std::ifstream infile{"input.txt"};

    uint64_t sum{};

    std::string game;
    uint64_t id;
    while (getline(infile, game)) {
        id = std::atoi(game.c_str() + 4);
        if (game_is_valid(game.substr(7 + n_digits(id))))
            sum += id;
    }

    std::cout << sum << '\n';
}
