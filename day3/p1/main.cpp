#include <array>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

constexpr char EMPTY = '.';

std::vector<std::string> load_lines(std::string_view input);
std::vector<std::string> split(std::ifstream& stream, char sep);

bool is_symbol(char c)
{
    return !(std::isdigit(c) || c == EMPTY);
}

bool is_symbol(size_t line_i,
               size_t col_i,
               const std::vector<std::string>& lines)
{
    return is_symbol(lines.at(line_i).at(col_i));
}

bool is_valid_index(ssize_t line_i,
                    ssize_t col_i,
                    const std::vector<std::string>& lines)
{
    if (line_i < 0 || line_i == lines.size())
        return false;
    if (col_i < 0 || col_i == lines.at(line_i).size())
        return false;
    return true;
}

bool has_symbol_around(size_t line_i,
                       size_t col_i,
                       const std::vector<std::string>& lines)
{
    const std::array<ssize_t, 2> deltaXs = {-1, 1};
    const std::array<ssize_t, 2> deltaYs = {-1, 1};

    for (ssize_t dX : deltaXs)
    {
        for (ssize_t dY : deltaXs)
        {
            if (is_valid_index(line_i + dY, col_i + dX, lines) &&
                is_symbol(line_i + dY, col_i + dX, lines))
                return true;
        }
    }
    return false;
}

bool is_valid(size_t line_i,
              std::optional<size_t> start,
              std::optional<size_t> end,
              const std::vector<std::string>& lines)
{
    if (!start)
        return false;

    return true;
}

int main(void)
{
    constexpr std::string_view INPUT = "short_input.txt";
    std::vector<std::string> lines = load_lines(INPUT);

    std::string line;
    std::optional<size_t> number_start;
    std::optional<size_t> number_end;
    bool is_part;

    size_t number;
    size_t sum{};

    for (size_t line_i = 0; line_i < lines.size(); line_i++)
    {
        line = lines[line_i];
        number_start = {};
        for (size_t col_i = 0; col_i < line.size(); col_i++)
        {
            if (!std::isdigit(line[col_i]))
                continue;
            if (!number_start && std::isdigit(line[col_i]))
                number_start = col_i;
            if (number_start && (!std::isdigit(line[col_i])))
            {
                number_end = col_i;
                is_part = is_valid(line_i, number_start, number_end, lines);
            }
        }
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
