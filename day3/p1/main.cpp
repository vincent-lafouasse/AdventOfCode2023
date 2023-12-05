#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define INPUT "short_input.txt"

std::vector<std::string> split(std::ifstream& stream, char sep);

int main(void)
{
    std::ifstream input_stream{INPUT};
    std::vector<std::string> lines = split(input_stream, '\n');
    input_stream.close();

    for (auto const& line : lines)
    {
        std::cout << line << '\n';
    }
}

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
