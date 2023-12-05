#include <fstream>
#include <iostream>
#include <optional>

#include <cctype>
#include <cstdint>
#include <cstdlib>

#define INPUT "input.txt"

std::optional<char> get_first(const std::string& s, int (*is)(int));
std::optional<char> get_last(const std::string& s, int (*is)(int));
short opt_char_to_int(std::optional<char> c);

int main() {
    std::ifstream infile{INPUT};

    std::optional<char> first_digit;
    std::optional<char> last_digit;

    uint64_t sum{};

    std::string line;
    while (infile >> line) {
        first_digit = get_first(line, &isdigit);
        last_digit = get_last(line, &isdigit);
        if (!first_digit)
            break;

        sum += 10 * opt_char_to_int(first_digit) + opt_char_to_int(last_digit);
    }

    std::cout << sum;
}

std::optional<char> get_first(const std::string& s, int (*is)(int)) {
    for (auto it = s.cbegin(); it != s.cend(); it++) {
        if ((*is)(*it)) {
            return {*it};
        }
    }
    return {};
}

std::optional<char> get_last(const std::string& s, int (*is)(int)) {
    for (auto it = s.crbegin(); it != s.crend(); it++) {
        if ((*is)(*it)) {
            return {*it};
        }
    }
    return {};
}

short opt_char_to_int(std::optional<char> c) {
    if (!c)
        return 0;
    if (!isdigit(c.value()))
        return 0;
    return c.value() - '0';
}
