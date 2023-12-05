#include <pthread.h>
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
typedef std::vector<std::string> Lines;

std::vector<std::string> load_lines(std::string_view input);
std::vector<std::string> split(std::ifstream& stream, char sep);
bool is_symbol(char c);

struct Position {
    Position(){};
    Position(i64 row, i64 col) : col(col), row(row) {}
    char in(const Lines& lines) const;
    bool is_valid(const Lines& lines) const;
    bool contains_symbol(const Lines& lines) const;
    std::vector<Position> neighbours(const Lines& lines) const;

    i64 col;
    i64 row;
};

struct Number {
    Number(Position pos, const Lines& lines) {
        this->pos = pos;
        std::string line = lines.at(pos.row);
        data = std::atoi(line.c_str() + pos.col);
    }
    std::vector<Position> neighbours(const Lines& lines) {
        std::vector<Position> out;
        const size_t len = std::to_string(data).length();
        Position candidate_above;
        Position candidate_below;

        for (size_t i = -1; i <= len; i++) {
            candidate_above = Position(pos.row - 1, pos.col + i);
            candidate_below = Position(pos.row + 1, pos.col + i);
            if (candidate_above.is_valid(lines))
                out.push_back(candidate_above);
            if (candidate_below.is_valid(lines))
                out.push_back(candidate_below);
        }
        Position candidate_before = Position(pos.row, pos.col - 1);
        Position candidate_after = Position(pos.row, pos.col + len);
        if (candidate_before.is_valid(lines))
            out.push_back(candidate_before);
        if (candidate_after.is_valid(lines))
            out.push_back(candidate_after);

        return out;
    }

    bool is_part(const Lines& lines) {
        std::vector<Position> __neighbours = neighbours(lines);

        for (const Position& neighbour : __neighbours) {
            if (neighbour.contains_symbol(lines))
                return false;
        }
        return true;
    }

    void log(const Lines& lines) {
        std::cout << data << " is part : " << is_part(lines) << '\n';
    }

    Position pos;
    i64 data;
};

int main(void) {
    constexpr std::string_view INPUT = "short_input.txt";
    Lines lines = load_lines(INPUT);

    std::optional<u32> start;

    for (u32 row = 0; row < lines.size(); row++) {
        start = {};
        for (u32 col = 0; col < lines[row].size(); col++) {
            Position pos{row, col};
            if (!start && std::isdigit(pos.in(lines))) {
                start = col;
            }
            if (start && (!std::isdigit(pos.in(lines)) ||
                          col == lines[row].size() - 1)) {
                Number n({row, start.value()}, lines);
                n.log(lines);
                start = {};
            }
        }
    }
}

Lines load_lines(std::string_view input) {
    std::ifstream input_stream{input};
    Lines lines = split(input_stream, '\n');
    input_stream.close();
    return lines;
}

std::vector<std::string> split(std::ifstream& stream, char sep) {
    std::vector<std::string> out{};

    std::string token;
    while (std::getline(stream, token, sep)) {
        out.push_back(token);
    }
    return out;
}

bool is_symbol(char c) {
    return !(std::isdigit(c) || c == EMPTY);
}

char Position::in(const Lines& lines) const {
    return lines.at(row).at(col);
}
bool Position::is_valid(const Lines& lines) const {
    if (row < 0 || static_cast<u32>(row) == lines.size())
        return false;
    if (col < 0 || static_cast<u32>(col) == lines.at(row).size())
        return false;
    return true;
}
bool Position::contains_symbol(const Lines& lines) const {
    return is_symbol(in(lines));
}
std::vector<Position> Position::neighbours(const Lines& lines) const {
    const std::array<i64, 2> dXs = {-1, 1};
    const std::array<i64, 2> dYs = {-1, 1};

    std::vector<Position> out;

    for (i64 dX : dXs) {
        for (i64 dY : dYs) {
            Position candidate{row + dX, col + dY};
            if (candidate.is_valid(lines))
                out.push_back(candidate);
        }
    }
    return out;
}
