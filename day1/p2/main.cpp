#include <array>
#include <fstream>
#include <iostream>
#include <optional>

#include <cctype>
#include <cstdint>
#include <cstdlib>

#define INPUT "input.txt"

std::optional<short> get_digit(const char* s);
std::optional<short> get_first_digit(const std::string& s);
std::optional<short> get_last_digit(const std::string& s);
short opt_char_to_int(std::optional<char> c);

const std::array<const char*, 9> WORD_DIGITS = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const char* digit_to_word(short n);

int main() {
    std::ifstream infile{INPUT};

    std::optional<short> first_digit;
    std::optional<short> last_digit;

    uint64_t sum{};

    std::string line;
    while (infile >> line) {
        first_digit = get_first_digit(line);
        last_digit = get_last_digit(line);
        if (!first_digit)
            break;

        sum += 10 * first_digit.value() + last_digit.value();
    }

    std::cout << sum;
}

std::optional<short> get_digit(const char* s) {
    if (isdigit(*s))
        return *s - '0';

    for (size_t digit = 1; digit < 10; digit++) {
        const char* digit_word = digit_to_word(digit);
        if (strncmp(s, digit_word, strlen(digit_word)) == 0) {
            return digit;
        }
    }
    return {};
}

std::optional<short> get_first_digit(const std::string& s) {
    std::optional<short> digit;
    const char* s__ = s.c_str();

    for (size_t i = 0; i < s.length(); i++) {
        digit = get_digit(s__ + i);
        if (digit)
            return digit;
    }
    return {};
}

std::optional<short> get_last_digit(const std::string& s) {
    std::optional<short> digit;
    const char* s__ = s.c_str();

    for (int i = s.length() - 1; i >= 0; i--) {
        digit = get_digit(s__ + i);
        if (digit)
            return digit;
    }
    return {};
}

const char* digit_to_word(short n) {
    return WORD_DIGITS.at(n - 1);
}
