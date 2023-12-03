#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#define INPUT "input.txt"

typedef std::array<int, 3> Hand;
enum Color
{
    RED,
    GREEN,
    BLUE
};

const Hand MAX = {12, 13, 14};

bool hand_is_possible(const Hand& hand, const Hand& MAX)
{
    for (size_t i = 0; i < hand.size(); i++)
    {
        if (hand[i] > MAX[i])
            return false;
    }
    return true;
}

bool hand_is_valid(const std::string& hand_str)
{
    std::stringstream hand_stream(hand_str);
    std::string buffer;
    Hand hand{};

    int n;
    std::string color;
    std::stringstream stream;

    while (getline(hand_stream, buffer, ','))
    {
        stream = std::stringstream(buffer);
        stream >> n;
        stream >> color;
        if (color == "red")
            hand[RED]++;
        else if (color == "green")
            hand[GREEN]++;
        else if (color == "blue")
            hand[BLUE]++;
        else
            return false;
    }

    return hand_is_possible(hand, MAX);
}

class Game
{
   public:
    Game() : id(0), valid(false) {}
    Game(const std::string& line)
    {
        std::stringstream stream(line);
        std::string garbage;

        stream >> garbage;
        stream >> id;
        stream >> garbage;

        std::string hand_str;
        while (getline(stream, hand_str, ';'))
        {
            if (!hand_is_valid(hand_str))
            {
                valid = false;
                return;
            }
        }
        valid = true;
    }

    int id;
    bool valid;
};

int main()
{
    std::ifstream infile{INPUT};

    uint64_t sum{};

    Game current_game;

    std::string line;
    while (getline(infile, line))
    {
        current_game = Game(line);
        if (current_game.valid)
            sum += current_game.id;
    }

    std::cout << sum << '\n';
}
