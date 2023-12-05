#include <array>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

constexpr char EMPTY = '.';
typedef int64_t i64;
typedef uint32_t u32;

std::vector<std::string> load_lines(std::string_view input);
std::vector<std::string> split(std::ifstream& stream, char sep);
bool is_symbol(char c);

struct Position
{
	Position(){};
	Position(i64 row, i64 col) : row(row), col(col) {}
	bool is_valid(const std::vector<std::string>& lines)
	{
		if (row < 0 || row == lines.size())
			return false;
		if (col < 0 || col == lines.at(row).size())
			return false;
		return true;
	}
	bool contains_symbol(const std::vector<std::string>& lines)
	{
		return is_symbol(lines.at(row).at(col));
	}
	std::vector<Position> neighbours(const std::vector<std::string>& lines)
	{
		const std::array<i64, 2> dXs = {-1, 1};
		const std::array<i64, 2> dYs = {-1, 1};

		std::vector<Position> out;

		for (i64 dX : dXs)
		{
			for (i64 dY : dYs)
			{
				Position candidate{row + dX, col + dY};
				if (candidate.is_valid(lines))
					out.push_back(candidate);
			}
		}
		return out;
	}

	i64 col;
	i64 row;
};

struct Range
{
	u32 start;
	u32 end;
};

int main(void)
{
    constexpr std::string_view INPUT = "short_input.txt";
    std::vector<std::string> lines = load_lines(INPUT);

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

bool is_symbol(char c)
{
    return !(std::isdigit(c) || c == EMPTY);
}
