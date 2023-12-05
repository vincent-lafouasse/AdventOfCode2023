#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

constexpr char EMPTY = '.';

std::vector<std::string> load_lines(std::string_view input);
std::vector<std::string> split(std::ifstream& stream, char sep);

int main(void)
{
    constexpr std::string_view INPUT = "short_input.txt";
    std::vector<std::string> lines = load_lines(INPUT);

    for (auto const& line : lines)
    {
        std::cout << line << '\n';
    }
}

std::vector<std::string> load_lines(std::string_view input)
{
    std::ifstream input_stream{input};
    std::vector<std::string> lines = split(input_stream, '\n');
    input_stream.close();
    return lines;
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
